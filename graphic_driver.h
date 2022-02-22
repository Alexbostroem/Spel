
void draw_object (POBJECT o);

void clear_object (POBJECT o);

void move_catobject (POBJECT o);

void move_mouseobject (POBJECT o);

void move_jump_catobject (POBJECT o);

void move_duck_catobject (POBJECT o);

int hits_roof(POBJECT o);

void set_object_speed (POBJECT o, int speedx, int speedy);

int exact_objects_overlap (POBJECT o1, POBJECT o2);


void graphic_initialize(void);

void graphic_clear_screen(void);

void graphic_pixel_set(int x, int y);

void graphic_pixel_clear(int x, int y);