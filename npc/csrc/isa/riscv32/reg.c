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
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
	int i;
	for(i=0;i<ARRLEN(regs);i++)
	{
		printf("%s \t %#x \t %u\n",regs[i],cpu.gpr[i],cpu.gpr[i]);//打印寄存器名字 16进制，10进制
	}	
	printf("pc \t %#x \t %u\n",cpu.pc,cpu.pc);
}
void isa_reg_display_ref(CPU_state *ref_r) {
	int i;
	printf("expected:\n");
	for(i=0;i<ARRLEN(regs);i++)
	{
		printf("%s \t %#x \t %u\n",regs[i],ref_r->gpr[i],ref_r->gpr[i]);//打印寄存器名字 16进制，10进制
	}	
	printf("pc \t %#x \t %u\n",ref_r->pc,ref_r->pc);
}
extern "C" void load_reg(word_t regv,int n ) {
	if(n==33)
		cpu.mtvec=regv;
	else if (n==34)
		cpu.mepc=regv;	
	else if (n==35)
		cpu.mcause=regv;
	else if(n==32)
		cpu.mstatus=regv;
	else
		cpu.gpr[n]=regv;
	//isa_reg_display();
}
extern "C" void reset_reg() {
    for(int i=0; i<32; i++) {
        cpu.gpr[i] = 0;
    }
	//isa_reg_display();
}
word_t isa_reg_str2val(const char *s, bool *success) {
	*success=true;
	int i;
	for(i=0;i<32;i++){
		if(strcmp(regs[i],s)==0)//将输入的字符串与寄存器满足进行匹配
		{
			break;
		}	
	}
	if(i==32)//若没有匹配成功，先看是不是特殊的0寄存器，否则就是没有此寄存器
	{
		if(s[0]=='0')
			return cpu.gpr[0];
		*success=false;
		return 0;
	}
	else
	{
		return cpu.gpr[i];//返回匹配的寄存器

	}

	return 0;
}
