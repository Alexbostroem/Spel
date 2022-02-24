#include "define_global.h"
#include "grafik.h"
#include "graphic_driver.h"

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
		graphic_pixel_set( (mygeo->px[i].x + o->posx), (mygeo->px[i].y + o->posy));
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
	

void clear_all_geo (POBJECT o){
		o->geo_number=run;
		clear_object(o);
		o->geo_number=stand;
		clear_object(o);
		o->geo_number=duck;
		clear_object(o);
		o->geo_number=jump;
		clear_object(o);
}


void move_catobject (POBJECT o){
	if (o->geo_number==jump){
		clear_all_geo(o);
		o->geo_number=jump;
		if(o->posy<=1){
			o->posy=0;
		}
		o->posy =(o->posy + o->diry);
		draw_object(o);
	}
	else if (o->geo_number==duck & o->posy >= START_POS_CAT){
		clear_all_geo(o);
		o->geo_number=duck;
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
	o->geo_number=stand;
	o->posx = (o->posx + o->dirx);
	draw_object(o);
	clear_object(o);
	o->geo_number=run;
	o->posx = (o->posx + o->dirx);
	draw_object(o);
} 
void move_damsugare (POBJECT o){
	
	clear_object(o);
	o->posx = (o->posx + o->dirx);
	draw_object(o);
} 

void set_object_speed (POBJECT o, int speedx, int speedy)
{
o->dirx=speedx;
o->diry=speedy;
}

int exact_objects_overlap (POBJECT o1, POBJECT o2){
  int offset1x = o1->posx;
  int offset1y = o1->posy;
  int offset2x = o2->posx;
  int offset2y = o2->posy;
  /*
  for (int i = 0; i < o1->geo->numpoints; i++) {
    for (int j = 0; j < o2-> geo->numpoints; j++)
      if ((offset1x + o1->geo->px[i].x == offset2x + o2->geo->px[j].x) &&
        (offset1y + o1->geo->px[i].y == offset2y + o2->geo->px[j].y)) 
		return 1;
  }
   * */
  return 0;
}


