__attribute__((naked))
void graphic_initalize(void);
__attribute__((naked))
void graphic_clear_screen(void);
__attribute__((naked))
void graphic_pixel_set(int x, int y);
__attribute__((naked))
void graphic_pixel_clear(int x, int y);
extern struct Obj;
extern struct GEOMETRY;
extern struct POINT;
//#include "define_global.h"

/*
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
*/

extern static GEOMETRY cat_jump_geometry; 
extern static GEOMETRY cat_run_geometry;
extern static GEOMETRY cat_stand_geometry;
	
OBJECT cat;