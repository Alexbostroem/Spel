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
#include "pointordeath_function.h"



void main(void)
{
	app_init();
	char *out_ascii;	// Pekare till den array som ska skrivas till asciidisplay
	char ascii_points[] = {0x30,'\0'};    // Aktuell poäng, uppdateras under spelets gång
	char ascii_GO[] = "GAME OVER! ";
	ascii_gotoxy(9,1);		// gå till col 9 rad 1 på asciidisplayen
	out_ascii = ascii_points;
	
	 while (*out_ascii) {
    	ascii_write_char(*out_ascii++);
    }
	// Ovan går att lägga i start_ascii. Är nollan vid start som skrivs ut efter "Points: "
	
	POBJECT m =&mouse;
	POBJECT d =&damsugare;
	POBJECT k =&cat;	
	POBJECT b =&bird;
	int write_counter_m = 0;
	int write_counter_b = 0;
	char c;


    while(1){
		
		if (ascii_points[0] >= 0x35){	// ascii_points[0] är nya points!!
			m->set_speed(m,-10,0);
			b->set_speed(b,-10,0);

		}
		
			m->move(m);
			k->move(k);
			d->move(d);
			b->move(b);
			c = keyb();
			switch(c)
			{
			case 2: k->geo_number = jump; k->set_speed(k,0,-6); break;
			case 8: k->geo_number = duck; break;
			default: k->geo_number = run; break;
			}
	
		
		if (approx(k,m) & k->geo_number==duck){
					//if (exact_objects_overlap(k,m)){
					m->clear_all(m);
					m->posx = 130;
					
					// EN POÄNG FÖR MUSEN
					ascii_points[0]++;
					ascii_gotoxy(9,1);
					out_ascii = ascii_points;
					while (*out_ascii) {
						ascii_write_char(*out_ascii++);
					}
				}
		//}
		if (approx(k,b) & k->geo_number==jump){
					//if (exact_objects_overlap(k,b)){
					
					b->clear_all(b);
					b->posx = 130;
					
					// TVÅ POÄNG FÖR FÅGEL
					ascii_points[0] += 2;
					ascii_gotoxy(9,1);
					out_ascii = ascii_points;
					while (*out_ascii) {
						ascii_write_char(*out_ascii++);
					}
				}
		//}
		if (approx(k,d)){
					//if (exact_objects_overlap(k,d)){
					k->clear_all(k);
					k->posx = 140;
					
					// GAME OVER OM DAMMSUGAREN SUGER I SIG KATTEN
					ascii_gotoxy(1,1);
					out_ascii = ascii_GO;
					while (*out_ascii) {
						ascii_write_char(*out_ascii++);
					}
					
					//}
		}
	}
	
}



