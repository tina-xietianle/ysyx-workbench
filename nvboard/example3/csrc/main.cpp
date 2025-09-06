#include <nvboard.h>
#include <Vspriled.h>

static Vspriled dut;

void nvboard_bind_all_pins(Vspriled* top);
void single_cycle ()
{
	dut.clk = 0; dut.eval();
	dut.clk = 1; dut.eval();
}

void reset (int n) {
	dut.rst =1;
	while(n -- > 0) single_cycle();
	dut.rst = 0;
}

int main()
{
	nvboard_bind_all_pins(&dut);
	nvboard_init();
	reset(10);
	while(1){
		nvboard_update();
		dut.eval();
		single_cycle();
	}
}
