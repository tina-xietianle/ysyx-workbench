#include <nvboard.h>
#include "Vme6.h"

void nvboard_bind_all_pins(Vme6* top) {
	nvboard_bind_pin( &top->clk, 1, BTNC);
	nvboard_bind_pin( &top->reset, 1, SW0);
	nvboard_bind_pin( &top->out, 8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->h, 14, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
}
