#include <nvboard.h>
#include "Vme3.h"

void nvboard_bind_all_pins(Vme3* top) {
	nvboard_bind_pin( &top->a, 4, SW8, SW7, SW6, SW5);
	nvboard_bind_pin( &top->b, 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->func, 3, BTNL, BTNC, BTNR);
	nvboard_bind_pin( &top->result, 4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->zero, 1, LD15);
	nvboard_bind_pin( &top->carry, 1, LD5);
	nvboard_bind_pin( &top->overflow, 1, LD8);
	nvboard_bind_pin( &top->out, 1, LD11);
}
