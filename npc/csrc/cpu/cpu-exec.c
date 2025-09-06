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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "disasm.h" // 包含头文件
#include <verilated.h>
#include <verilated_vcd_c.h>  
#include "Vysyx_24090010_exu.h"
// Declare or include the definition of npc_state
#include <utils.h>
// #include "/home/xietianle/ysyx-workbench/npc/csrc/utils/state.c"
#include <elf.h>
#include "/home/xietianle/ysyx-workbench/npc/csrc/monitor/sdb/sdb.h"
#include "/home/xietianle/ysyx-workbench/npc/include/ftrace.h"
/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
extern Vysyx_24090010_exu* top;
extern VerilatedVcdC* tfp;
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
    strncpy(irb[position].logbuf, lb, sizeof(irb[position].logbuf) - 1);//存入logbuf，要留一个位置给'\0'
    irb[position].logbuf[128] = '\0'; 
    position = (position + 1) % 8;//更新位置，8个位置循环
}
void print_inst(){
    for(int i = 0; i < 8; i++){//打印环形缓冲区
    #ifdef CONFIG_DIFFTEST
        if(i!=position-2)  // 如果定义了CONFIG_DIFFTEST，使用position-2,因为当前指令是刚取出来的，不是实现错误的指令
    #else
        if(i!=position-1)  // 否则使用position-1，在verilog中刚取出来就被执行了，因为我的invalid_inst函数是在组合逻辑中，所以这里就是当前指令错了。
    #endif
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
Decode s;
int finish=0;
void device_update();
                            //一个decode *s   一个cpu.pc
static void trace(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (CONFIG_ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  // IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));//execute函数有循环调用本函数，即执行一条指令便会调用一次
  IFDEF(CONFIG_WATCHPOINT, scan_wp());  
}
//用于跟踪和差分测试指令执行的结果
static void difftest(Decode *_this, vaddr_t dnpc) {
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
}
extern "C" void transfer_cpu (vaddr_t pc,vaddr_t next_pc,uint32_t inst){
  s.pc = pc;
  s.dnpc = next_pc;
  s.isa.inst.val =inst;
  s.snpc = pc+4;
  // printf("transfer:%0x",s.dnpc);
}
extern "C" void ebreak()
{
	Verilated::gotFinish(true);	
	finish=1;
}
uint64_t dump_time=0;
static void exec_once( vaddr_t pc) {
  top->clk = !top->clk;
  top->eval();
  tfp->dump(5 + dump_time);
  dump_time++;
  top->clk = !top->clk;
  top->eval();
  tfp->dump(5 + dump_time);
  // printf("exec_once:%0x\n",s.dnpc);
  cpu.pc = s.pc;

#ifdef CONFIG_FTRACE
  static vaddr_t last_pc = 0;
  static uint32_t last_inst = 0;
  // 确保同一条指令不会被重复跟踪
  
  if (s.pc != last_pc) {
    uint32_t inst_f = s.isa.inst.val;
  if((inst_f & 0x7f) == 0x6f) {
    uint32_t rd = (inst_f >> 7) & 0x1f;
    if (rd != 0) {
    int32_t imm = ((inst_f & 0x80000000) >> 11) | // 符号位
                   ((inst_f & 0x7fe00000) >> 20) |  // 10:1位
                   ((inst_f & 0x00100000) >> 9) |   // 11位
                   (inst_f & 0x000ff000);           // 19:12位
      // 符号扩展
      if (inst_f & 0x80000000) imm |= 0xffe00000;
      vaddr_t target = s.pc + imm;
      print_func(s.pc, target, 0);   
    }
  }
  else if ((inst_f & 0x7f) == 0x67) {
      uint32_t rd = (inst_f >> 7) & 0x1f;
      uint32_t rs1 = (inst_f >> 15) & 0x1f;
      // 是函数返回还是普通跳转
      int is_ret = (rd == 0 && rs1 == 1); // x1(ra)寄存器返回
      print_func(s.pc, s.dnpc, is_ret);
     
    }
  last_pc = s.pc;
  last_inst = s.isa.inst.val;
  }
#endif
  
#ifdef CONFIG_ITRACE
  char *p =s.logbuf;
  p += snprintf(p, sizeof(s.logbuf), FMT_WORD ":", s.pc);
  // printf("%s\n", s.logbuf);
  int ilen = s.snpc - s.pc;
  int i;
  uint8_t *inst = (uint8_t *)&s.isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  //printf("%s\n", s.logbuf);
  int ilen_max = 4;
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;
  // save_inst(s.pc, s.isa.inst.val, s.logbuf);//保存指令iringbuf.
  // if (npc_state.state == NPC_ABORT){//如果状态为ABORT，打印指令
  //   print_inst();
  // }
#ifndef CONFIG_ISA_loongarch32r
  // extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s.logbuf + sizeof(s.logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s.snpc, s.pc), (uint8_t *)&s.isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}
//执行一条指令
static void execute(uint64_t n) {
  int chushi=n;
  vaddr_t regpc;
  for (;n > 0; n --) {
    regpc = cpu.pc;
    exec_once(cpu.pc);
    
    if(finish==1){//用一个全局变量在ebreak出现时，改变他的数值，然后在主函数中判断，结束仿真
      // printf("break\n");
      tfp->close();//结束波形生成
      top->final();//结束仿真
      delete top;//释放内存
      delete tfp;//释放内存
      break;
    }
    g_nr_guest_inst ++;
    dump_time++;
    // printf("11111\n");
    trace(&s, cpu.pc);
    if(n!=chushi)   //npc慢一排，所以让nemu等一下再run
      difftest(&s, regpc);
    // printf("22222\n");
    IFDEF(CONFIG_ITRACE, save_inst(s.pc, s.isa.inst.val, s.logbuf));//保存指令iringbuf.
    
    if (npc_state.state == NPC_ABORT){//如果状态为ABORT，打印指令
      print_inst();
    }
    
    if (npc_state.state != NPC_RUNNING) break;
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
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
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
  // printf("11111\n");
  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      // printf("33333\n");
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
      // printf("22222\n");
      // fall through
    case NPC_QUIT: statistic();
  }

}
