/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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

#include <isa.h>
#include <memory/paddr.h>
#include "disasm.h" // 包含头文件
#include <elf.h>
#include "/home/xietianle/ysyx-workbench/npc/include/ftrace.h"
void init_rand();
void init_log(const char *log_file);
void init_mem();
extern void init_difftest(const char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
// void init_disasm(const char *triple);
#define __GUEST_ISA__ riscv32e
static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
 Log("Exercise: Please remove me in the source code and compile NPC again.");
 // assert(0);
}
//用来打印调试信息。
#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;
static char *elf_file = NULL;//elf文件名，多个函数要用到，所以设为全局变量

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // 返回内置默认镜像的大小
  }
//加载镜像文件到内存中，并返回镜像文件的大小
  FILE *fp = fopen(img_file, "rb");//以二进制读模式打开镜像文件
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);//将文件指针移动到文件末尾
  long size = ftell(fp);//获取文件指针的当前位置即文件大小
//获取镜像文件大小
  Log("The image is %s, size = %ld", img_file, size);

  // 在load_img函数中添加额外调试信息

  fseek(fp, 0, SEEK_SET);//将文件指针移动到文件开头
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);//将镜像文件读取到内存中
  assert(ret == 1);  //^ 将虚拟机的重置向量地址转换为主机地址

  fclose(fp);
  return size;
  //关闭文件并返回镜像文件大小
}

//char *elf_file = NULL;//elf文件名，多个函数要用到，所以设为全局变量

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {"elf"      , required_argument, NULL, 'e'},//{长选项名，是否需要参数，flag，短选项名}如果flag为NULL，则val字段的值将作为getopt_long()函数的返回值
    {0          , 0                , NULL,  0 },
  };
  //解析命令行参数
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {//getopt_long()函数用来解析命令行参数
    switch (o) {//optarg为全局变量，这个变量在getopt_long()函数中会被赋值为对应选项的参数
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg; break;//将-e的参数，elf文件名传给elf_file
      case 1: img_file = optarg; return 0;//当getopt_long()函数遇到一个非选项参数时会返回1,且optarg会指向这个非选项参数
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf file           read elf file\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}
//根据不同的命令行参数执行相应操作
void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);
  //将elf文件传给处理elf文件的函数
  treat_elf(elf_file);  //在初始化的时候就分析完elf文件，给后面用
  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();//初始定义内存

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();//初始化内存内容

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();//将镜像即指令等加载到内存中去，并返回镜像的大小
  
  #ifdef CONFIG_DIFFTEST
  init_difftest(NEMU_SO, img_size, difftest_port);
  #else
  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);
  #endif
  
  /* Initialize the simple debugger. */
  init_sdb();//初始化正则表达式，监视点

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE, init_disasm("riscv32" "-pc-linux-gnu"));
  //初始化反汇编器
#endif

  /* Display welcome message. */
  welcome();
}
//用于初始化监视器
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  treat_elf(elf_file);   //因为am_init_monitor()函数和init_monitor()函数并齐，所以在这里也要调用treat_elf()函数
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
