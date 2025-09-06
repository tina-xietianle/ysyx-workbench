/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.

*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/vaddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");//获取用户输入，将用户输入给line_read，若用户没有输入，则line_read=NULL

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
	nemu_state.state= NEMU_QUIT;	
	return -1;
}

static int cmd_help(char *args);
static int cmd_si(char *args) {
	uint64_t n;
	if(args==NULL)
		n=1;
	else
		sscanf(args,"%lu",&n);
	
		
	cpu_exec(n);
	return 0;
		
}
static int cmd_info(char *args) {
	if(strcmp(args,"r")==0)
		isa_reg_display();
	else if(strcmp(args,"w")==0)
		print_wp();
	else
		printf("erro,the standard format is 'info SUBCMD'\n");
	return 0;
}
static int cmd_x(char *args) {
	char *arg1, *arg2;
	int n,i;
	bool success=1;
	vaddr_t address;
	word_t content;
	arg1=strtok(NULL, " ");
	arg2=strtok(NULL, " ");
	if(arg1==NULL){
		printf("format: x N EXPR\n");
		return 0;
	}
	if(arg2==NULL){
		printf("format: x N EXPR\n");
		return 0;
	}
	sscanf(arg1 , "%d",&n);
	address=expr(arg2,&success);
	if(!success){
		printf("计算错误\n");
		return 0;
	}
	for(i=0;i<n;i++,address += 4)
	{
		if(address>0x87ffffff)
		{
			printf("The address is too big\n range [0x80000000,0x87ffffff]\n");
			return 0;
		}
		if(address<0x80000000)
		{
			printf("The address is too small\n range [0x80000000,0x87ffffff]\n");
			return 0;
		}
		content = vaddr_read (address,4);
		printf("%#x :\t %u\n",address,content);
	}
	return 0;
}
static int cmd_p(char *args){
	bool success;
	word_t result;
	success=true;
	if(args==NULL){
		printf("format: p expr\n");
		return 0;
	}
	
	result= expr(args ,&success);
	if(success)
		printf("result=%u\n",result);
	else
		printf("erro\n");
	return 0;
}
static int cmd_w(char *args){
	bool success=1;
	word_t result;
	if(args==NULL)
	{
		printf("nothing to watch\n");
		return 0;
	}
	result=expr(args,&success);
	if(!success)
		printf("The expr have problem\n");
	else
		build_wp(args,result);
	return 0;
}
static int cmd_d(char *args)
{
	int no;
	if(args==NULL)
	{
		printf("nothing to delete\n");
		return 0;
	}
	sscanf(args , "%d",&no);
	delete_wp(no);
	return 0;
}
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },

  /* TODO: Add more commands */
  { "si", "make the program excute N instuctions and stop,while the N is not given,it will be 1", cmd_si},
  { "info", "print register status or print watchpoint status", cmd_info},
  { "x", "Calculate the value of the expression EXPR and output the result as the starting memory address in hexadecimal format, continuously for N 4-byte values.", cmd_x},
  { "p", "calculate the value of expr.", cmd_p},
  { "w", "when the expr changed,stop the program", cmd_w},
  { "d", "delete the N watchpoint", cmd_d},
};

#define NR_CMD ARRLEN(cmd_table) //NR_CMD为cmd_table这个数组的成员数

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);//str_end是指向用户输入的最后一个字符的地址

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");//将str字符串以空格分隔，并返回第一个字符的地址给cmd
    if (cmd == NULL) { continue; } //当第一个字符都没有时，就跳过后面的，继续去从用户那获取

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;//args是一个指向（被strtok分隔的）第二个字符的首部的指针
    if (args >= str_end) { //如果用户只输入一项，则args会因为多了一个空格为（1），比str_end大1,则args会被if制0,否则args为第二项
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {//与table里面的进行匹配
        if (cmd_table[i].handler(args) < 0) { return; }//要是q，函数会返回-1，然后，执行if，回到main函数
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
