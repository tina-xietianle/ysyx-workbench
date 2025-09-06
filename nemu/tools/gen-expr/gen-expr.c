/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>


// this should be enough
static char buf[65536] = {},buf_eval[6553600]={};
static char code_buf[6553600] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned  result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

int choose(int n)
{
	return rand() % n;
}
static void gen (char c)
{
	
	char ch[2]={c,'\0'};
	strcat(buf,ch);
	strcat(buf_eval,ch);
}
static void gen_num ()
{
	char num[10];
	sprintf(num,"%d",rand() % 100);
	strcat(buf ,num);
	strcat(buf_eval,num);
}
static void gen_rand_op()
{
	char op[4]={'+','*','-','/'};
		gen(' ');
		gen(op[choose(4)]);
		gen(' ');
	
}
static void gen_rand_expr() {
	char p[]="(unsigned)";
	if(strlen(buf)==65534)
		return ;
	switch (choose(3)) {
	    case 0:
			gen_num();
			break;
		case 1: 
			strcat(buf_eval,p);
			gen('('); 
			gen_rand_expr(); 
			gen(')'); 
			break;
		default:
			gen_rand_expr(); 
			gen_rand_op(); 
			gen_rand_expr(); 
			break;
	}
	
}


int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);//设置rand的种子值
  int loop = 1;//默认循环次数
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);//用户输入循环数目
  }
  int i;
  for (i = 0; i < loop; i ++) {
	buf_eval[0]='\0';  
	  buf[0]='\0';  
    gen_rand_expr();//生成随机表达式

    sprintf(code_buf, code_format, buf_eval);//格式化的字符串存在code_buf

    FILE *fp = fopen("/tmp/.code.c", "w");//打开文件，写入模式
    assert(fp != NULL);//判断是否成功打开
    fputs(code_buf, fp);//将刚刚生成的格式化的字符串code_buf，写入文件fp中
    fclose(fp);//关闭文件

    int ret = system("gcc -Wall -Werror /tmp/.code.c -o /tmp/.expr");//编译
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");//以只读的形式打开，fp是一个管道
    assert(fp != NULL);

    unsigned result;
    ret = fscanf(fp, "%u", &result);//从管道fp中以整形读取，存入result
    pclose(fp);//关闭管道

     printf("%u %s\n", result, buf);//打印计算结果和表达式
  }
  return 0;
}
