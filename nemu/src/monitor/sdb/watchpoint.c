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

#include "sdb.h"

#define NR_WP 5

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  word_t data;
  char expr[100];
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}
//监视点的初始化
/* TODO: Implement the functionality of watchpoint */
WP* new_wp()
{
	WP* temp=NULL;
	if(free_==NULL)
	{
		printf("don't have free watchpoint\n");
		//assert(0);
		return temp;
	}
	temp=free_;//把free_链表里的头领出来
	free_=free_->next;//空闲链表头变为原本的下一个
	temp->next=head;//将这个新的watchpoint放在head前面，即他的下一个是原本已有的链表的头

	head=temp;//使用的链表的头变为这个新加的
	return temp;//返回新加的链表的地址
	
}
void free_wp(WP *wap)
{
	WP *temp;
	if(wap == NULL)
	{
		printf("The watchpoint is NULL\n");
		assert(0);
	}
	if(wap==head)
	{
		head=wap->next;//因为在下面的循环是从temp即head的下一个开始匹配的，所有head归为空闲需要单拿出来讨论
		wap->next=free_;
		free_=wap;
		
		return ;
	}
	temp=head;//从head开始遍历循环，停在wap的上一个，将其的next指向wap的next
	while(temp)
	{
		if(temp->next==wap)
		{
			break;
		}
		temp=temp->next;
	}
	temp->next=wap->next;
	wap->next=free_;
	free_=wap;
}
void build_wp(char *args, word_t result)
{
	WP *new=new_wp();
	//从空闲中获取一个监视点
	if(new==NULL)
		return;
	new->data=result;//传入数据，和表达式
	strcpy(new->expr,args);
	printf("Succeed to build a watchpoint %d: %s\n",new->NO,new->expr);
}
void print_wp()
{
	WP *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("not have watchpoint\n");
	}
	else{
		
		while(temp)
		{
			printf("NO:%d\texpr:%s\tvalue:%u\n",temp->NO,temp->expr,temp->data);//从头开始遍历，并打印监视点的编号，表达式，数据
			temp=temp->next;
		}
	}
}
void delete_wp(int NO)
{
	WP *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("not have watchpoint to delete\n");
	}
	else{
		while(temp)//如果匹配了就结束循环，或者temp遍历到了NULL
		{
			if(NO==temp->NO)
				break;
			temp=temp->next;
		}
		if(temp==NULL)
			printf("The watchpoint is not exist\n");
		else{
			free_wp(temp);//归位
			printf("delete success\n");
		}
	}
}
void scan_wp()
{
	bool success=true;
	WP *temp=head;
	word_t value;
	if(temp==NULL)
		return;
	else{
		while(temp)
		{
            value=expr(temp->expr,&success);
			if(temp->data!=value)
			{
				nemu_state.state=NEMU_STOP;
				printf("The watchpoint %d: %s value change\n",temp->NO,temp->expr);
				printf("old: %u\t new: %u\n",temp->data,value);
				temp->data=value;
				return;
			}
			temp=temp->next;
		}
	}
}
