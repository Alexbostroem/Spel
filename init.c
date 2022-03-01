#include "define_global.h"
#include "ascii_display.h"
#include "grafik.h"
#include "graphic_driver.h"
#include "init.h"
#include "keypad_driver.h"
#include "irq_handler.h"

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

void start_ascii(void) {
	char *startword;
	char ascii_start[] = "Points: "; // ska alltid skrivas vid start av spelet (endast 1 gång)
	ascii_gotoxy(1,1);		// gå till rad 1, col 1
    startword = ascii_start;
	 while (*startword) {
    	ascii_write_char(*startword++);
    }
	 
}

void init_app_ascii(void) {
	*GPIO_E_MODER = 0x55555555;	// Sätt portE pin 0-15 som utgångar
    ascii_init();
	start_ascii();
}

void irq_handler_int(void) {
	*SCB_VTOR = 0x2001C000;
	*((void(**)(void))SYSTICK_IRQ)= systick_irq_handler;
	
}

void app_init(void) {
	keyboard_init();
	display_init();
	init_app_ascii();
	irq_handler_int();
}