#include<nvboard.h>
#include<Vme2.h>

static Vme2 dut;

void nvboard_bind_all_pins(Vme2* top);

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
