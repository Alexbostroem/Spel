#include "define_global.h"

void keyboard_init(void) {
	*GPIO_D_MODER &= 0x00000000; 
	*GPIO_D_MODER |= 0x55005555; 
	*GPIO_D_OTYPER &= 0x0000; 
	*GPIO_D_PUPDR &= 0x0000FFFF;										
	*GPIO_D_PUPDR |= 0x00AA0000;
}

void app_init(void) {
	keyboard_init();
}