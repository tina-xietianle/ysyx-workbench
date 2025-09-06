#include "/home/xietianle/ysyx-workbench/npc/include/ftrace.h"

int symtab_num=0;  //符号表中的项数，即符号表的大小/sizeof(Elf32_Sym)
Elf32_Sym *symtab=NULL;  //符号表
char *strtab=NULL;      //字符串表
//将这三个变量设为外部变量是因为treat_elf和print_func函数都要用到这三个变量
int print_depth=0;  //调用函数的深度，调用函数会多打印一个空格，返回会少打印一个空格

void print_func(vaddr_t addr, vaddr_t next, int is_ret) {
  if (symtab == NULL || strtab == NULL || symtab_num <= 0) {
    printf("Error: Symbol table not initialized\n");
    return;
  }
  if (addr == 0x8000000c ) {
    // 硬编码处理第一条指令
    printf("0x%0x: []call [_trm_init@0x%0x]\n", addr, next);
    print_depth++;
    return;
  }
  int temp_dnpc = 0;
  int temp_pc = 0;
  bool found_dnpc = false;
  bool found_pc = false;
  
  // 查找目标函数
  for(temp_dnpc = 0; temp_dnpc < symtab_num; temp_dnpc++) {
    if(symtab[temp_dnpc].st_info ==0x12) {
      if(next >= symtab[temp_dnpc].st_value && 
         next <= symtab[temp_dnpc].st_value + symtab[temp_dnpc].st_size) {
        found_dnpc = true;
        break;
      }
    }
  }
  
  // 查找当前函数
  for(temp_pc = 0; temp_pc < symtab_num; temp_pc++) {
    if(symtab[temp_pc].st_info == 0x12) {
      if(addr >= symtab[temp_pc].st_value && 
         addr < symtab[temp_pc].st_value + symtab[temp_pc].st_size) {
        found_pc = true;
        break;
      }
    }
  }
  
  // 安全检查：如果没找到匹配的函数，使用默认值
  if (!found_pc || !found_dnpc) {
    printf("Warning: Function not found at 0x%x or 0x%x\n", addr, next);
    return;
  }
  
  // 检查字符串表索引是否有效
  if (symtab[temp_pc].st_name >= 0x10000 || symtab[temp_dnpc].st_name >= 0x10000) {
    printf("Warning: Invalid string table index\n");
    return;
  }
  
  if(is_ret) {
    printf("\033[0;36m0x%0x:\033[0m", addr);
    for(int i = 0; i <= print_depth; i++)
      printf(" ");
    printf("\033[0;36m[%s]ret  [%s]\033[0m\n", 
           strtab + symtab[temp_pc].st_name, 
           strtab + symtab[temp_dnpc].st_name);
    print_depth--;
  } else {
    printf("0x%0x:", addr);
    for(int i = 0; i <= print_depth; i++)
      printf(" ");
    printf("[%s]call [%s@0x%0x]\n", 
           strtab + symtab[temp_pc].st_name, 
           strtab + symtab[temp_dnpc].st_name, next);
    print_depth++;
  }
}



void treat_elf(const char *elf_file){
  if(elf_file==NULL)
    return;
  FILE *file = fopen(elf_file, "rb");//以二进制、只读方式打开elf文件
  int i=0;
  if(file == NULL){  //打开失败的报错
    printf("open file failed\n");
    fclose(file);
    exit(0);
  }
  //读取elf头表
  Elf32_Ehdr elf_header;  //定义一个elf头表
  fseek(file, 0, SEEK_SET);//将文件指针移动到文件开头
  i=fread(&elf_header, 1, sizeof(Elf32_Ehdr), file);//读取Elf32_Ehdr大小的数据到elf_header中
  if(i<=0)//读取elf头表失败的报错
  {
    printf("read file header failed\n");
    fclose(file);
    exit(0);
  }
  if(elf_header.e_ident[0] != 0x7f || elf_header.e_ident[1] != 'E' || elf_header.e_ident[2] != 'L' || elf_header.e_ident[3] != 'F'){
    printf("not a elf file\n");//不是elf文件的报错，elf文件的前四个字节为0x7f,'E','L','F'
    fclose(file);
    exit(0);
  }
    //读取节头表
  i=0;
  Elf32_Shdr *section_headers=NULL;//定义一个节头表，不知道具体有多少个节，所以先设为NULL，虽然elf头表中有节的数量，但是在定义的时候需要具体数值，1,2,。。。。
  section_headers = (Elf32_Shdr *)malloc(elf_header.e_shnum * sizeof(Elf32_Shdr));//动态分配内存，大小为节头表项数*每个项的大小
  for(int n=0; n<elf_header.e_shnum; n++){//节头表是一项一项循环读取的
    fseek(file, elf_header.e_shoff + n * sizeof(Elf32_Shdr), SEEK_SET);//将文件指针移动到节头表的偏移量处，读下一项时，指针会加一个项的大小，再读下一项
    i=fread(&section_headers[n], 1, sizeof(Elf32_Shdr), file);//读取一个节头表项的大小到section_headers[n]中
    if(i<=0)//读取节头表失败的报错
    {
        free(section_headers);
        fclose(file);
        printf("read section header failed\n");
        exit(0);
    }
  }
  //读取字符串表
  i=0;
  int n=0;
  for( n=0; n<elf_header.e_shnum; n++){//遍历节头表，找到字符串表的位置
    if(section_headers[n].sh_type == SHT_STRTAB){//第一个类型为SHT_STRTAB的节就是字符串表
      break;
    }
  }
  int strtab_position = n;
  strtab = (char *)malloc(section_headers[strtab_position].sh_size);//动态分配内存，大小在节头表对应位置有存
  fseek(file, section_headers[strtab_position].sh_offset, SEEK_SET);//将文件指针移动到字符串表的偏移量处
  i=fread(strtab, 1, section_headers[strtab_position].sh_size,file);//读取字符串表的大小到strtab中
  if(i<=0)//读取字符串表失败的报错
  {
    printf("read strtab failed\n");
    free(strtab);
    free(section_headers);
    fclose(file);
    exit(0);
  }
  //找到符号表
  i=0;
  int symtab_position = 0;
  while(symtab_position <elf_header.e_shnum){//遍历节头表，找到符号表的位置
    if(section_headers[symtab_position].sh_type == SHT_SYMTAB){//只有一个是这个类型
      break;
    }
    symtab_position++;
  }
  if(symtab_position == elf_header.e_shnum){//没有符号表的报错
    printf("no symtab\n");
    free(strtab);
    free(section_headers);
    fclose(file);
    exit(0);
  }
  //读取符号表
  i=0;
  symtab = (Elf32_Sym *)malloc(section_headers[symtab_position].sh_size);//动态分配内存，大小在节头表对应位置有存
  fseek(file, section_headers[symtab_position].sh_offset, SEEK_SET);//将文件指针移动到符号表的偏移量处
  i=fread(symtab, 1, section_headers[symtab_position].sh_size, file);//读取符号表的大小到symtab中
  if(i<=0)//读取符号表失败的报错
  {
    free(strtab);
    free(symtab);
    free(section_headers);
    fclose(file);
    printf("read section header failed\n");
    exit(0);
  }
  symtab_num=section_headers[symtab_position].sh_size/sizeof(Elf32_Sym);//计算符号表的项数，可以减少一点，不然在print_func函数中每次都要计算
  
  //释放动态内存
  fclose(file);

  free(section_headers);
  return ;
}
