#include <nvboard.h>
#include <Vdoubles.h>

static Vdoubles dut;

void nvboard_bind_all_pins(Vdoubles* top);

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
