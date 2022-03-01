#include "startup.h"
#include "define_global.h"
#include "ascii_display.h"
#include "grafik.h"
#include "graphic_driver.h"
#include "init.h"
#include "keypad_driver.h"
#include "pointordeath_function.h"
#include "irq_handler.h"

int approx( POBJECT o1, POBJECT o2 ) {
  GEOMETRY *catgeo;
  GEOMETRY *objgeo;
  
	if (o1->geo_number == stand){
	catgeo= o1->geo_stand;
	}
	else if (o1->geo_number==run){
	catgeo= o1->geo_run;
	}
	else if (o1->geo_number==jump){
	catgeo= o1->geo_jump;
	}else if(o1->geo_number==duck){
		catgeo = o1->geo_duck;
	}
	
	if (o2->geo_number == stand){
	objgeo = o2->geo_stand;
	}
	else if(o2->geo_number==run){
	objgeo = o2->geo_run;
	}
	

	if (((o1->posx +catgeo->sizex) >= o2->posx & (o1->posx +catgeo->sizex) <=(o2->posx + objgeo->sizex))| o1->posx >= o2->posx & o1->posx <= o2->posx + objgeo->sizex ){
		if (((o1->posy <= o2->posy) & (o1->posy + catgeo->sizey) >= o2->posy) | (o1->posy <= (o2->posy + objgeo->sizey) & (o1->posy + catgeo->sizey) >= (o2->posy + objgeo->sizey))){
				return 1;
		}
	}
	else {
		return 0;
	}
}

		


int exact_objects_overlap (POBJECT o1, POBJECT o2){
  GEOMETRY *catgeo;
  GEOMETRY *objgeo;
  
	if (o1->geo_number == stand){
	catgeo= o1->geo_stand;
	}
	else if (o1->geo_number==run){
	catgeo= o1->geo_run;
	}
	else if (o1->geo_number==jump){
	catgeo= o1->geo_jump;
	}else if(o1->geo_number==duck){
		catgeo = o1->geo_duck;
	}
	
	if (o2->geo_number == stand){
	objgeo = o2->geo_stand;
	}
	else if(o2->geo_number==run){
	objgeo = o2->geo_run;
	}

  int offset1x = o1->posx;
  int offset1y = o1->posy;
  int offset2x = o2->posx;
  int offset2y = o2->posy;
  
  for (int i = 0; i < catgeo->numpoints; i++) {
    for (int j = 0; j < objgeo->numpoints; j++) {
      if ((offset1x + catgeo->px[i].x == offset2x + objgeo->px[j].x) &&
        (offset1y + catgeo->px[i].y == offset2y + objgeo->px[j].y)) 
		return 1;
   }
  }
  
  return 0;
}