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
	draw_object_run(o);
	clear_object_run(o);
	draw_object(o);
}