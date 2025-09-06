#include <nvboard.h>
#include "Vme2.h"

void nvboard_bind_all_pins(Vme2* top) {
	nvboard_bind_pin( &top->i, 8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->en, 1, SW8);
	nvboard_bind_pin( &top->y, 3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->eno, 1, LD4);
	nvboard_bind_pin( &top->h, 7, SEG0G, SEG0F, SEG0E, SEG0D, SEG0C, SEG0B, SEG0A);
}
