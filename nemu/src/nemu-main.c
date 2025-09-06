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

#include <common.h>
#include <ftrace.h>
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
void test();
word_t expr(char *e,bool *success);
int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
  /* Start engine. */
//  test();
  engine_start();
  // free(strtab);
  // free(symtab);//释放malloc的空间
  return is_exit_status_bad();
}
//void test ()
//{
//	FILE *file;
//	//int i,j;
//	word_t result;
//	bool success=true;
//	char line[65536];
	
//		int f=0,r=0;
//	file=fopen("/home/xietianle/ysyx-workbench/nemu/tools/gen-expr/test2","r");//打开测试文件
//	if(file==NULL)
//	{
//		printf("无法打开");
//		return ;
//	}
//	while(fgets(line,sizeof(line),file)!=NULL){//获取一行
//		uint32_t ans;//测试答案
//		char expr_test[65536];//测试表达式
//		if(sscanf(line,"%u %[^\n]",&ans,expr_test)==2)//以无符号整形 字符序列（以\n结尾），将line分成答案和表达式，且确保是分2
//		{
//			success=true;
//			result=expr(expr_test,&success);//将表达式传入expr函数，答案返回给result
//			
//			if(result==ans&&success==true){//若result等于ans，且success，则打印测试正确
//				r++;
//			}
//			else
//				f++;
//		}
//		printf("right:%d\terror:%d\n",r,f);
//	}
//	fclose(file);//关闭文件
//}
