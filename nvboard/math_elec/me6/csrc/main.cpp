#include<nvboard.h>
#include<Vme6.h>

static Vme6 dut;

void nvboard_bind_all_pins(Vme6* top);

int main()
{
	nvboard_bind_all_pins(&dut);
	nvboard_init();

	while(1)
	{
		nvboard_update();
		dut.eval();
	}
}
