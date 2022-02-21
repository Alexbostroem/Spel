#define MAX_POINTS 1300

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
}OBJECT, *POBJECT;

enum geometri_cat {stand,run,jump,duck};
