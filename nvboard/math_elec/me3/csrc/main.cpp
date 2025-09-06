#include<nvboard.h>
#include<Vme3.h>

static Vme3 dut;

void nvboard_bind_all_pins(Vme3* top);

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
