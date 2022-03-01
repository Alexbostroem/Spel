#include "irq_handler.h"
#include "define_global.h"


void set_clock(){
    flag=0;
    *STK_CTRL = 0;
    *STK_LOAD = (168-1);    // 168 cp ger 1 us
    *STK_VAL = 0;
    *STK_CTRL = 7;        // Bit 2 = 1 (systemklocka), bit 0 = 1 (räknare aktiv, ENABLE-bit)
}

void systick_irq_handler(void) {
	
}