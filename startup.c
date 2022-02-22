/*
 * 	startup.c
 *
 */
__attribute__((naked)) __attribute__((section (".start_section")) )
void startup ( void )
{
__asm__ volatile(" LDR R0,=0x2001C000\n");		/* set stack */
__asm__ volatile(" MOV SP,R0\n");
__asm__ volatile(" BL main\n");					/* call main */
__asm__ volatile(".L1: B .L1\n");				/* never return */
}

/*	SPELREGLER KATTIS
 * 	1. Katten rör sig endast i y-led. Ducka för att äta mus(1p), hoppa för att äta fågel(2p), hoppa över dammsugare(game over).
 * 	2. Poängen står i ascii-displayen. Står "game over" om dammsugaren fångar Kattis.
 * 	3. Undersök om ett objekt (mus,fågel,dammsugare) är i kontakt med Kattis genom att först kolla så de är på samma
 * 	x-koordinat. If ((kattis->posx + kattis->size->x) == objekt->posx)
 * 	kolla sedan om någon av objektets y-koordinater är samma som någon av kattis y-koordinater.
 * 	
 * */

#include "define_global.h"
#include "ascii_display.h"
#include "grafik.h"
#include "graphic_driver.h"
#include "keypad_driver.h"

void app_init(void) {
	*GPIO_D_MODER &= 0x00000000;	// Nollställer bit 31-16 resten kvarstår
	*GPIO_D_MODER |= 0x55005555;	// 0101 0101 0101 0101 (bit 31-16) resten kvarstår, bit 31-16 utsignaler med varje pin representerade med 2 bitar
	*GPIO_D_OTYPER &= 0x0000;	//	Nollställ bit 15-12 i OTYPER (push-pull), bit 11-8 kvarstår. utpinnar som push-pull
	*((unsigned long *) GPIO_D_BASE + 0x0E) &= 0x00000000;
	*((unsigned long *) GPIO_D_BASE + 0x0E) |= 0x00AA0000;	//	Sätt pull-down (1010) på inpinnar i register PUPDR(2bit/pin)
	
}

void main(void){
	app_init();
	graphic_initialize();
	graphic_clear_screen();
	char c;
	//struct cat_o = cat_o;
	//struct cat_ptr = {cat};
	
	draw_object(catptr_grafik);
	
	/*
	while (1) {
		cat_ptr->move(cat_ptr);
		c = keyb();
		switch(c)
		{
			case 6: cat_ptr->set_speed(cat_ptr,2,0); break;
			case 4: cat_ptr->set_speed(cat_ptr,-2,0); break;
			case 5: cat_ptr->set_speed(cat_ptr,0,0); break;
			case 2: cat_ptr->set_speed(cat_ptr,0,-2); break;
			case 8: cat_ptr->set_speed(cat_ptr,0,2); break;
				default:
				cat_ptr->set_speed(cat_ptr,0,0); break;
		}
	}
	*/
	
}
