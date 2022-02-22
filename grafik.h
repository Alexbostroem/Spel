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

extern struct GEOMETRY cat_jump_geometry; 
extern struct GEOMETRY cat_run_geometry;
extern struct GEOMETRY cat_stand_geometry;
	
extern struct OBJECT cat;
extern struct OBJECT mouse;