#include "define_global.h"
#include "ascii_display.h"
#include "grafik.h"
#include "graphic_driver.h"
#include "init.h"
#include "keypad_driver.h"

void keyboard_init(void) {
	*GPIO_D_MODER &= 0x00000000; 
	*GPIO_D_MODER |= 0x55005555; 
	*GPIO_D_OTYPER &= 0x0000; 
	*GPIO_D_PUPDR &= 0x0000FFFF;										
	*GPIO_D_PUPDR |= 0x00AA0000;
}

void display_init(void) {
	graphic_initialize();
	graphic_clear_screen();
}

void init_app_ascii(void) {
	*GPIO_E_MODER = 0x55555555;	// Sätt portE pin 0-15 som utgångar
    ascii_init();
}

void app_init(void) {
	keyboard_init();
	display_init();
	init_app_ascii();
}