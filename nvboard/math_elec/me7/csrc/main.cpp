#include <nvboard.h>
#include <Vme7.h>

static TOP_NAME dut;//实例

void nvboard_bind_all_pins(Vme7* top);//绑引脚

static void single_cycle() {//模拟时钟信号
  dut.clk = 0; dut.eval();
  dut.clk = 1; dut.eval();
}

static void reset(int n) {
  dut.rst = 1;
  while (n -- > 0) single_cycle();
  dut.rst = 0;
}

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();//初始化仿真环境

  reset(10);

  while(1) {
    nvboard_update();//更新仿真环境
    single_cycle();//模拟时钟信号
  }
}
