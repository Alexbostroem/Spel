#include "define_global.h"

//GLOBAL
int keyb_state = 0;

void ActivateRow( unsigned int row ) {

	switch( row )
	{
	case 1: *GPIO_D_ODR_HIGH = 0x10; break;
	case 2: *GPIO_D_ODR_HIGH = 0x20; break;
	case 3: *GPIO_D_ODR_HIGH = 0x40; break;
	case 4: *GPIO_D_ODR_HIGH = 0x80; break;
	case 5: *GPIO_D_ODR_HIGH = 0xF0; break;
	case 0: *GPIO_D_ODR_HIGH = 0x00; break;
	}
}


int ReadColumn( void )
{ 
unsigned char c;
c = *GPIO_D_IDR_HIGH;
if ( c & 0x8 ) return 4;
if ( c & 0x4 ) return 3;
if ( c & 0x2 ) return 2;
if ( c & 0x1 ) return 1;
return 0;
}

unsigned char keyb_enhanced(void)
	{
		unsigned char key[]={1,2,3,0xA,4,5,6,0xB,7,8,9,0xC,0xE,0,0xF,0xD};
		int row, col;
		
		if (keyb_state == 1) {
			ActivateRow(5);
			
			if(col = ReadColumn()) {
				keyb_state = 1;
			 }
			 
			 else {
				 keyb_state = 0;
				 return 0xFF;
				 }
			}
		
		
		if (keyb_state == 0) {
			
			for(row=1; row <=4 ; row++ ) {
					ActivateRow(row);
					if((col = ReadColumn()) ){
						keyb_state = 1;
						ActivateRow(0);
						return key [4*(row-1)+(col-1) ];
				}
			}
		}
		
		ActivateRow(0);
		return 0xFF;
}
/*
void ActivateRow (unsigned int row){
	switch (row) 
	{ 
	case 1: *GPIO_ODR_HIGH = 0x10; break;
	case 2: *GPIO_ODR_HIGH = 0x20; break;
	case 3: *GPIO_ODR_HIGH = 0x40; break;
	case 4: *GPIO_ODR_HIGH = 0x80; break;
	case 0: *GPIO_ODR_HIGH = 0x00; break;
	}
	
}
*/

unsigned char keyb(void)
{	
	unsigned char key []={1,2,3,0xA,4,5,6,0xB,7,8,9,0xC,0xD,0,0xF,0xD};
	int row,col;
	for (row=1; row<=4;row++){
	ActivateRow (row);
	if ((col=ReadColumn())){
		ActivateRow(0);
		return key [4*(row-1)+(col-1)];
		}
	}
	ActivateRow(0);
	
	return 0xFF;
}