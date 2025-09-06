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
//对ram的操作
word_t vaddr_ifetch(vaddr_t addr, int len) {//专门用来读取内存中的指令的一个函数
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
  paddr_write(addr, len, data);
}

extern "C" word_t vaddr_ifetch_v(vaddr_t addr, int len) {//专门用来读取内存中的指令的一个函数
  return paddr_read(addr, len);
}

extern "C" word_t vaddr_read_v(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

extern "C" void vaddr_write_v(vaddr_t addr, int len, word_t data) {
  // if (addr == 0xa00003f8) {
  //   // printf("11111\n");
  //   putchar((char)data); // 输出一个字符到终端
  //   return;
  //   // printf("if里面,%x\n",addr);
  // }
  // printf("if外面,%x\n",addr);
  paddr_write(addr, len, data);
}
