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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <elf.h>
#include "/home/xietianle/ysyx-workbench/nemu/src/monitor/sdb/sdb.h"
#include "/home/xietianle/ysyx-workbench/nemu/include/ftrace.h"
/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
typedef struct {
    vaddr_t pc;
    uint32_t inst;
    char logbuf[128];
} IringBuf ;//用于保存指令、pc、等的环形缓冲区
//extern char *strtab;   //因为字符串表和字符表一直要有，所有要在执行完所有命令后释放
//extern Elf32_Sym *symtab;  //即在此声明，给cpu_exec用
IringBuf irb[8] ;//8个记忆部分
uint32_t position = 0;//当前位置
char *p = irb->logbuf;
void save_inst(vaddr_t pc, uint32_t inst, char *lb) {
    irb[position].pc = pc;//存入pc
    irb[position].inst = inst;//存入指令
    // strncpy(irb[position].logbuf, lb, sizeof(irb[position].logbuf) - 1);//存入logbuf，要留一个位置给'\0'
    // irb[position].logbuf[sizeof(irb[position].logbuf) - 1] = '\0'; 
    snprintf(irb[position].logbuf, sizeof(irb[position].logbuf), "%s", lb);
    position = (position + 1) % 8;//更新位置，8个位置循环
}
void print_inst(){
    for(int i = 0; i < 8; i++){//打印环形缓冲区
        if(i!=position-1)
            printf("    %s\n", irb[i].logbuf);
        else{
            printf("\33[1;36m" "--> %s\n" "\33[0m", irb[i].logbuf);//当前位置的前一个是出错的指令，打印不同颜色及箭头
        }
    }
}
CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;//记录执行的指令数
static uint64_t g_timer = 0; //记录执行指令所用的时间
static bool g_print_step = false;//控制是否打印每一步的执行信息

void device_update();
                            //一个decode *s   一个cpu.pc
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));//execute函数有循环调用本函数，即执行一条指令便会调用一次
  IFDEF(CONFIG_WATCHPOINT, scan_wp());  
}
//用于跟踪和差分测试指令执行的结果
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  // printf("%s\n", s->logbuf);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  //printf("%s\n", s->logbuf);
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;
  // save_inst(s->pc, s->isa.inst.val, s->logbuf);//保存指令iringbuf.
  // if (nemu_state.state == NEMU_ABORT){//如果状态为ABORT，打印指令
  //   print_inst();
  // }
#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}
//执行一条指令
static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    //trace_and_difftest(&s, cpu.pc);
    
    trace_and_difftest(&s, cpu.pc);
    IFDEF(CONFIG_ITRACE,save_inst(s.pc, s.isa.inst.val, s.logbuf));//保存指令iringbuf.
    if (nemu_state.state == NEMU_ABORT){//如果状态为ABORT，打印指令
      print_inst();
    }
    if (nemu_state.state != NEMU_RUNNING) break;
   // if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
	IFDEF(CONFIG_WATCHPOINT,scan_wp());
  }
}
//执行指定数量的指令
static void statistic() {//打印统计信息，包括执行时间，指令数，执行频率
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }
//只有状态为RUNNING时，才可以继续往后
  uint64_t timer_start = get_time();

  execute(n);
  free(strtab);
  free(symtab);//释放malloc的空间
//进行循环测试，当state不是RUNNING时，或者n<=0时，才回这里
  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;
//计算所用时间
  
  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);

      // fall through
    case NEMU_QUIT: statistic();
  }
}
