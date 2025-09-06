
#include <common.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vysyx_24090010_exu.h" // Verilator生成的头文件
void init_monitor(int, char *[]);
void engine_start();
int is_exit_status_bad();
word_t expr(char *e,bool *success);
Vysyx_24090010_exu* top= NULL;
VerilatedVcdC* tfp =NULL ;
int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top = new Vysyx_24090010_exu;
    // 初始化波形生成
  top->trace(tfp, 99);
  tfp->open("waveform.vcd");
  // 初始化信号
  top->clk = 0;
  top->rst = 1;

  init_monitor(argc, argv);

  for (int i = 0; i <= 4; i++) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(i);
    }
    top->rst = 0;
  /* Start engine. */
  engine_start();
  

  return is_exit_status_bad();
}
