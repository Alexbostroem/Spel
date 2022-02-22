
#include "define_global.h"
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

#include "grafik.h"

void draw_object (POBJECT o){
	if (o->geo_number==stand){
		for ( int i=0; i <= (o->geo_stand->numpoints-1); i++){
		graphic_pixel_set( (o->geo_stand->px[i].x + o->posx), (o->geo_stand->px[i].y + o->posy));
		}
	}
	else if (o->geo_number==run){
		for ( int i=0; i <= (o->geo_run->numpoints-1); i++){
		graphic_pixel_set( (o->geo_run->px[i].x + o->posx), (o->geo_run->px[i].y + o->posy));
		}
	}
	else if (o->geo_number==jump){
		for ( int i=0; i <= (o->geo_jump->numpoints-1); i++){
		graphic_pixel_set( (o->geo_jump->px[i].x + o->posx), (o->geo_jump->px[i].y + o->posy));
		}
	}
	else if (o->geo_number==duck){
		for ( int i=0; i <= (o->geo_duck->numpoints-1); i++){
		graphic_pixel_set( (o->geo_duck->px[i].x + o->posx), (o->geo_duck->px[i].y + o->posy));
		}
	}
}

void clear_object (POBJECT o){
	if (o->geo_number==stand){
		for ( int i=0; i <= (o->geo_stand->numpoints-1); i++){
		graphic_pixel_clear( (o->geo_stand->px[i].x + o->posx), (o->geo_stand->px[i].y + o->posy));
		}
	}
	else if (o->geo_number==run){
		for ( int i=0; i <= (o->geo_run->numpoints-1); i++){
		graphic_pixel_clear( (o->geo_run->px[i].x + o->posx), (o->geo_run->px[i].y + o->posy));
		}
	}
	else if (o->geo_number==jump){
		for ( int i=0; i <= (o->geo_jump->numpoints-1); i++){
		graphic_pixel_clear( (o->geo_jump->px[i].x + o->posx), (o->geo_jump->px[i].y + o->posy));
		}
	}
	else if (o->geo_number==duck){
		for ( int i=0; i <= (o->geo_duck->numpoints-1); i++){
		graphic_pixel_clear( (o->geo_duck->px[i].x + o->posx), (o->geo_duck->px[i].y + o->posy));
		}
	}
}

void move_catobject (POBJECT o){
	
	clear_object(o);
	o->geo_number=run;
	draw_object(o);
	clear_object(o);
	o->geo_number=stand;
	draw_object(o);
} 

void move_catobject (POBJECT o){
	
	clear_object(o);
	o->geo_number=run;
	draw_object(o);
	o->posx = (o->posx + o->dirx);
	clear_object(o);
	o->geo_number=stand;
	draw_object(o);
} 
void move_jump_catobject (POBJECT o){
	clear_object(o);
	o->geo_number=jump;
	o->posy=(o->posy+o->diry)
	if (hits_roof){
		o->diry=0;
	}
	draw_object(o);
}	

void move_duck_catobject (POBJECT o){
	clear_object(o);
	o->geo_number=duck;
	draw_object(o);
}

int hits_roof(POBJECT o){
	 if (o->posx < 1){
		return 1;
	}
	else {
		return 0;
	}
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
  for (int i = 0; i < o1->geo->numpoints; i++) {
    for (int j = 0; j < o2-> geo->numpoints; j++)
      if ((offset1x + o1->geo->px[i].x == offset2x + o2->geo->px[j].x) &&
        (offset1y + o1->geo->px[i].y == offset2y + o2->geo->px[j].y)) 
		return 1;
  }
  return 0;
}


