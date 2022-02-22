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

void main(void)
{
	
}

