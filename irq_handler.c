#include "startup.h"
#include "define_global.h"
#include "ascii_display.h"
#include "grafik.h"
#include "graphic_driver.h"
#include "init.h"
#include "keypad_driver.h"
#include "pointordeath_function.h"
#include "irq_handler.h"

void set_clock(){
    *STK_CTRL = 0;
    *STK_LOAD = (168-1);    // 168 cp ger 1 us
    *STK_VAL = 0;
    *STK_CTRL = 7;        // Bit 2 = 1 (systemklocka), bit 0 = 1 (räknare aktiv, ENABLE-bit)
}

void systick_irq_handler(void) {
	ascii_gotoxy(9,1);
	char *out_ascii = ascii_points;
	 while (*out_ascii) {
    	ascii_write_char(*out_ascii++);
    }
	set_clock();
}