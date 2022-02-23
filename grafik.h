
//STRUCTS
typedef struct POINT{
	char x,y;
} POINT,*PPOINT;

typedef struct GEOMETRY
{
	int numpoints;
	int sizex;
	int sizey;
	POINT px [MAX_POINTS];	
}GEOMETRY,*PGEOMETRY;

typedef struct Obj{
	PGEOMETRY geo_stand;
	PGEOMETRY geo_run;
	PGEOMETRY geo_jump;
	PGEOMETRY geo_duck;
	int geo_number;
	int dirx, diry;
	int posx, posy;
	void (* draw) (struct Obj*);
	void (* clear) (struct Obj*);
	void (* move) (struct Obj*);
	void (* set_speed) (struct Obj*, int, int);
} OBJECT, *POBJECT;


extern GEOMETRY cat_jump_geometry; 
extern GEOMETRY cat_run_geometry;
extern GEOMETRY cat_stand_geometry;

extern OBJECT cat;
extern OBJECT mouse;
extern OBJECT bird;
extern OBJECT damsugare;
