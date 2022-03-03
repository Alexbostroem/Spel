#include "define_global.h"
#include "grafik.h"
#include "graphic_driver.h"
#include "init.h"

__attribute__((naked))
void graphic_initialize (void)
{
__asm volatile(" .HWORD 0xDFF0\n");	
__asm volatile(" BX LR\n");		
}
__attribute__((naked))
void graphic_clear_screen(void)
{
__asm volatile(" .HWORD 0xDFF1\n");	
__asm volatile(" BX LR\n");		
}
__attribute__((naked))
void graphic_pixel_set(int x, int y)
{
__asm volatile(" .HWORD 0xDFF2\n");	
__asm volatile(" BX LR\n");		
}
__attribute__((naked))
void graphic_pixel_clear(int x, int y)
{
__asm volatile(" .HWORD 0xDFF3\n");	
__asm volatile(" BX LR\n");		
}


void draw_object (POBJECT o){
	GEOMETRY *mygeo;
	if (o->geo_number == stand){
	mygeo= o->geo_stand;
	}
	else if (o->geo_number==run){
	mygeo= o->geo_run;
	}
	else if (o->geo_number==jump){
	mygeo= o->geo_jump;
	}
	else if (o->geo_number==duck){
		mygeo= o->geo_duck;
	}
		for ( int i=0; i <= (mygeo->numpoints-1); i++){
		if ( mygeo->px[i].x >0){
		graphic_pixel_set( (mygeo->px[i].x + o->posx), (mygeo->px[i].y + o->posy));
		}
	}
}
	
void clear_object (POBJECT o){
		GEOMETRY *mygeo;
	if (o->geo_number == stand){
	mygeo= o->geo_stand;
	}
	else if (o->geo_number==run){
	mygeo= o->geo_run;
	}
	else if (o->geo_number==jump){
	mygeo= o->geo_jump;
	}
	else if (o->geo_number==duck){
		mygeo= o->geo_duck;
	}
		for ( int i=0; i <= (mygeo->numpoints-1); i++){
		graphic_pixel_clear( (mygeo->px[i].x + o->posx), (mygeo->px[i].y + o->posy));
	}
}
	
void clear_prev_object (POBJECT o){
		GEOMETRY *mygeo;
	if (o->prev_geo == stand){
	mygeo= o->geo_stand;
	}
	else if (o->prev_geo==run){
	mygeo= o->geo_run;
	}
	else if (o->prev_geo==jump){
	mygeo= o->geo_jump;
	}
	else if (o->prev_geo==duck){
		mygeo= o->geo_duck;
	}
		for ( int i=0; i <= (mygeo->numpoints-1); i++){
		graphic_pixel_clear( (mygeo->px[i].x + o->posx), (mygeo->px[i].y + o->posy));
	}
}

void clear_all_geo (POBJECT o){
		o->geo_number=stand;
		clear_object(o);
		o->geo_number=duck;
		clear_object(o);
		o->geo_number=jump;
		clear_object(o);
		o->geo_number=run;
		clear_object(o);
}


void move_catobject (POBJECT o){
	if (o->geo_number==jump & o->posy <= START_POS_CAT){
		clear_prev_object(o);
		if(o->posy<=1){
			o->posy=0;
		}
		o->posy =(o->posy + o->diry);
		draw_object(o);
	}
	else if (o->geo_number==duck & o->posy >= START_POS_CAT){
		clear_prev_object(o);
		o->posy= (START_POS_CAT + 5); 
		draw_object(o);
	}
	else if (o->posy < START_POS_CAT & o->geo_number!=jump ){
		o->geo_number=jump;
		clear_object(o);
		o->posy = (o->posy + (-1*o->diry));
		draw_object(o); 
	}
	else if (o->posy > START_POS_CAT & o->geo_number!=duck){
		o->geo_number=duck;
		clear_object(o);
		o->posy=START_POS_CAT;
		o->geo_number=stand;
		draw_object(o); 
		
	}
	else {
	o->diry=0;
	clear_all_geo(o);
	o->geo_number=run;
	draw_object(o);
	clear_object(o);
	o->geo_number=stand;
	draw_object(o);
	}
} 

void move_mouseobject (POBJECT o){
	
	clear_object(o);
	
	if ( o->geo_number==stand){
		o->geo_number=run;
		o->posx = (o->posx + o->dirx);
		draw_object(o);
	}
	else if ( o->geo_number==run){
		o->geo_number=stand;
		o->posx = (o->posx + o->dirx);
		draw_object(o);
		
	}
	else if
	(o->posx + 40 < 1){
		o->posx= (128);
	}

} 
void move_damsugare (POBJECT o){
	
	clear_object(o);
	o->posx = (o->posx + o->dirx);
	draw_object(o);
	if
	(o->posx + 40 < 1){
		o->posx= (128);
	}
} 

void set_object_speed (POBJECT o, int speedx, int speedy)
{
o->dirx=speedx;
o->diry=speedy;
}




