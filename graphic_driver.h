
void draw_object (POBJECT o);

void clear_object (POBJECT o);

void move_catobject (POBJECT o){
	clear_object(o);
	draw_object_run(o);
	clear_object_run(o);
	draw_object(o);
} 
