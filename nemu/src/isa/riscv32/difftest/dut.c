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

#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r) {
  bool temp=true;
  int i=0;
  for(i=0;i<32;i++){//遍历寄存器，若32个寄存器与真机的都相同，则temp任为true
    if(ref_r->gpr[i] != cpu.gpr[i]){
      temp=false;
    
    }
  }
  if(temp==true && ref_r->pc==cpu.pc){//在32个寄存器都相同的情况下，若pc也相同，则返回true
    //printf("%0x,%0x\n",ref_r->pc,cpu.pc);
    return true;
  }
  // printf("no %0x,%0x\n",ref_r->pc,cpu.pc);
  // printf("0x%x\n",ref_r->pc);
  // pc=ref_r->pc;                    //若不相同，则将ref_r->pc赋值给pc,让报错时，报这个地方的错
  // printf("0x%x\n",pc);
  // //printf("no,%d\n",temp);
  return false;
}

void isa_difftest_attach() {
}
