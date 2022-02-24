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
#include "init.h"
#include "keypad_driver.h"


void main(void)
{
	app_init();
	
	POBJECT m =&mouse;
	POBJECT d =&damsugare;
	POBJECT k =&cat;	
	POBJECT b =&bird;

	

	char c;
	int points;

    while(1){
		
		if (points> 20){
			m->set_speed(m,0,-10);
			b->set_speed(b,0,-10);
		}
		
			m->move(m);
			k->move(k);
			//d->move(d);
			//b->move(b);
			c = keyb();
			switch(c)
			{
			case 2: k->geo_number = jump; k->set_speed(k,0,-6); break;
			case 8: k->geo_number = duck; break;
			default: k->geo_number = run; break;
			}
		delay_micro(200);
		
		if ((k->posx + 30) > m->posx & k->geo_number==duck){
					//if (exact_objects_overlap(m,k)){
					//delay_micro(500);
					m->clear_all(m);
					m->posx = 130;
					//}
		}
	}

}



