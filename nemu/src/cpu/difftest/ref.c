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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  // printf("11111");
  if (direction == DIFFTEST_TO_REF) {
    // 从 DUT 复制到 REF (NEMU)
    memcpy(guest_to_host(addr), buf, n);
  } else {
    // 从 REF (NEMU) 复制到 DUT
    memcpy(buf, guest_to_host(addr), n);
  }
  // assert(0);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  // printf("222222");
  if (direction == DIFFTEST_TO_REF) {
    // 从 DUT 复制寄存器状态到 REF
    CPU_state *dut_state = (CPU_state *)dut;
    memcpy(&cpu, dut_state, sizeof(CPU_state));
  } else {
    // 从 REF 复制寄存器状态到 DUT
    CPU_state *dut_state = (CPU_state *)dut;
    memcpy(dut_state, &cpu, sizeof(CPU_state));
  }
  // assert(0);
}

__EXPORT void difftest_exec(uint64_t n) {
  // printf("33333");
  cpu_exec(n);
  // assert(0);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  isa_raise_intr(NO, cpu.pc);
  // assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
