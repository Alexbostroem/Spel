

// FUNKTIONER FÖR ATT SKRIVA TILL ASCII DISPLAY

#include "define_global.h"
#define SIMULATOR

void init_app(void) {
    *GPIO_E_MODER = 0x55555555;    // Sätt portE pin 0-15 som utgångar
}    

void delay_250ns( void ) {
/* SystemCoreClock = 168000000 */
    *STK_CTRL = 0;
    *STK_LOAD = ( (168/4) -1 );    // 168 cp ger 1 us -> 168/4 cp ger 0.25 us = 250 ns
    *STK_VAL = 0;
    *STK_CTRL = 5;   	 // Bit 2 = 1 (systemklocka), bit 0 = 1 (räknare aktiv, ENABLE-bit)
    
    while( (*STK_CTRL & 0x10000 )== 0 );    // Väntar på att räknaren räknat ner 250ns
    *STK_CTRL = 0;   						 // Stäng av räknaren
}

void delay_micro(unsigned int us) {
    #ifdef SIMULATOR    // Simulator mycket långsammare än hårdvara
   	 us = us / 1000;
   	 us++;    // För att undvika att us skulle vara 0
    #endif
    
    while( us > 0 ) {
   	 delay_250ns();
   	 delay_250ns();
   	 delay_250ns();
   	 delay_250ns();    // 0.25 us * 4 = 1 us
   	 us--;
    }
}

void delay_milli(unsigned int ms) {
    #ifdef SIMULATOR    // Simulator mycket långsammare än hårdvara
   	 ms = ms / 1000;
   	 ms++;    // För att undvika att ms skulle vara 0
    #endif
    
    while( ms > 0 ) {
   	 for (int c = 1 ; c <= 1000 ; c++) {
   		 delay_250ns();  // 1 us * 1000 = 1 ms
   		 delay_250ns();
   		 delay_250ns();
   		 delay_250ns();
   	 }
   	 ms--;
    }
}

void ascii_ctrl_bit_set(unsigned char x) {
    *GPIO_E_ODR_LOW = B_SELECT | x | *GPIO_E_ODR_LOW;
}

void ascii_ctrl_bit_clear(unsigned char x) {
    *GPIO_E_ODR_LOW = B_SELECT | (*GPIO_E_ODR_LOW & ~x);
}

void ascii_write_controller(unsigned char byte) {
    ascii_ctrl_bit_set(B_E);
    *GPIO_E_ODR_HIGH = byte;
    delay_250ns();  	 
    ascii_ctrl_bit_clear(B_E);
}

unsigned char ascii_read_controller(void) {
    ascii_ctrl_bit_set(B_E);
    delay_250ns();    
    delay_250ns();
    unsigned char rv = *GPIO_E_IDR_HIGH;    // Ändrat enl. kod nedan
    ascii_ctrl_bit_clear(B_E);
    return rv;
}

unsigned char ascii_read_status(void) {
    *GPIO_E_MODER = 0x00005555;
    ascii_ctrl_bit_clear(B_RS);
    ascii_ctrl_bit_set(B_RW);
    unsigned char rv = ascii_read_controller();
    *GPIO_E_MODER = 0x55555555;
    return rv;
}

unsigned char ascii_read_data(void) {
    *GPIO_E_MODER = 0x00005555;
    ascii_ctrl_bit_set(B_RS);
    ascii_ctrl_bit_set(B_RW);
    unsigned char rv = ascii_read_controller();
    *GPIO_E_MODER = 0x55555555;
    return rv;
}

void ascii_write_cmd(unsigned char command) {
    ascii_ctrl_bit_clear(B_RS);
    ascii_ctrl_bit_clear(B_RW);
    ascii_write_controller(command);
}

void ascii_write_data(unsigned char data) {
    ascii_ctrl_bit_set(B_RS);
    ascii_ctrl_bit_clear(B_RW);
    ascii_write_controller(data);
}

void ascii_init(void) {
    while( ( ascii_read_status() & 0x80)== 0x80 ) {}    // Vänta tills statusflaggan är 0
    delay_micro( 8 ); /* latenstid för kommando */
    ascii_write_cmd( 1 ); /* kommando: "Clear display" */
    delay_milli( 2 ); /* i stället för 1,53 ms */
    // FUNCTION SET
    while( ( ascii_read_status() & 0x80)== 0x80 ) {}    // Vänta tills statusflaggan är 0
    delay_micro( 8 ); /* latenstid för kommando */
    ascii_write_cmd(56);    // Med "dont care" bitarna som 0
    delay_micro(39);
    // DISPLAY CONTROL
    while( ( ascii_read_status() & 0x80)== 0x80 ) {}    // Vänta tills statusflaggan är 0
    delay_micro( 8 ); /* latenstid för kommando */
    ascii_write_cmd(14);
    delay_micro(39);
    // ENTRYMODE SET
    while( ( ascii_read_status() & 0x80)== 0x80 ) {}    // Vänta tills statusflaggan är 0
    delay_micro( 8 ); /* latenstid för kommando */
    ascii_write_cmd(4);
    delay_micro(39);
    
}

void ascii_write_char(unsigned char c) {
    // Ska skriva ut till display, ett tecken i taget
    while( ( ascii_read_status() & 0x80)== 0x80 ) {}    // Vänta tills statusflaggan är 0
    delay_micro( 8 ); /* latenstid för kommando */
    ascii_write_data( c );
    delay_micro(45);
}

void ascii_gotoxy(int x, int y) {    // y = row , x = cols
    // Sätt startadress till
    
    int adress = (x-1);
    
    if (y == 2) {
   	 adress = (adress + 0x40);
    }
    ascii_write_cmd((0x80 | adress));
}

int main(void)
{    /*
    char *s;
    char test1[] = "Alfanumerisk ";
    char test2[] = "Display - test";
    
    init_app();
    ascii_init();
    ascii_gotoxy(1,1);
    s = test1;
    
    while (*s) {
   	 ascii_write_char(*s++);
    }
    ascii_gotoxy(1,2);
    s = test2;
    while (*s) {
   	 ascii_write_char(*s++);
    }
    
    return 0;
     */
}
