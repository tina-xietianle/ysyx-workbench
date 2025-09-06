#include <nvboard.h>
#include <Vme1.h>

static Vme1 dut;

void nvboard_bind_all_pins(Vme1* top);

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
