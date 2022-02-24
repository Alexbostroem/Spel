
#include "define_global.h"
#include "grafik.h"
#include "graphic_driver.h"



 GEOMETRY cat_jump_geometry =
	{
		188,
		43,20,
		{
		{0,18},{0,22},
		{1,17},{1,19},{1,21},{1,23},
		{2,17},{2,19},{2,20},{2,22},{2,23},
		{3,17},{3,19},{3,20},{3,22},
		{4,17},{4,19},{4,20},{4,22},
		{5,17},{5,19},{5,20},{5,22},
		{6,17},{6,20},{6,22},
		{7,7},{7,8},{7,9},{7,17},{7,19},{7,22},
		{8,6},{8,10},{8,17},{8,19},{8,22},
		{9,7},{9,8},{9,11},{9,17},{9,19},{9,22},
		{10,9},{10,12},{10,17},{9,19},{9,22},
		{11,10},{11,13},{11,14},{11,17},{11,18},{11,22},
		{12,11},{12,15},{12,17},{12,18},{12,23},
		{13,12},{13,15},{13,17},{13,16},{13,23},
		{14,13},{14,23},
		{15,14},{15,23},
		{16,15},{16,16},{16,24},
		{17,15},{17,24},
		{18,15},{18,24},
		{19,15},{19,24},
		{20,15},{20,23},
		{21,15},{21,23},
		{22,15},{22,23},
		{23,15},{23,23},
		{24,16},{24,23},
		{25,16},{25,18},{25,20},{25,23},
		{26,9},{26,10},{26,11},{26,12},{26,13},{26,14},{26,15},{26,16},{26,17},{26,18},{26,19},{26,20},{26,23},
		{27,8},{27,18},{27,20},{27,23},
		{28,9},{28,18},{28,20},{28,23},{28,24},
		{29,10},{29,21},{29,24},
		{30,11},{30,19},{30,21},{30,24},
		{31,12},{31,16},{31,20},{31,21},{31,24},
		{32,12},{32,18},{32,20},{32,21},{32,25},
		{33,12},{33,18},{33,19},{33,21},{33,25},
		{34,12},{34,18},{34,20},{34,21},{34,25},
		{35,12},{35,16},{35,20},{35,21},{35,25},
		{36,11},{36,19},{36,21},{36,25},
		{37,10},{37,21},{37,22},{37,25},
		{38,9},{38,18},{38,20},{38,22},{38,25},
		{39,8},{39,18},{39,20},{39,23},{39,25},
		{40,9},{40,10},{40,11},{40,12},{40,13},{40,14},{40,15},{40,16},{40,17},{40,18},{40,19},{40,20},{40,23},{40,25},{40,26},
		{41,18},{41,20},{41,23},{41,25},{41,26},
		{42,18},{42,20},{42,23},{42,25},{42,26},
		{43,24},{43,25},
		}
	};
	
 GEOMETRY cat_run_geometry =
	{
		196,
		43,30,
		{
		{11,12},{11,13},{11,14},{11,15},{11,16},{11,17},{11,18},
		{12,9},{12,10},{12,11},{12,19},{12,20},{12,21},
		{13,7},{13,8},{13,22},{13,23},{13,24},{13,25},{13,26},{13,27},{13,28},{13,29},
		{14,6},{14,11},{14,30},
		{15,5},{15,8},{15,9},{15,10},{15,12},{15,24},{15,25},{15,26},{15,27},{15,28},{15,30},
		{16,4},{16,7},{16,12},{16,23},{16,29},{16,30},
		{17,3},{17,7},{17,12},{17,22},{17,30},
		{18,0},{18,1},{18,12},{18,3},{18,5},{18,12},{18,21},{18,22},
		{19,0},{19,12},{19,22},{19,23},{19,24},{19,25},
		{20,1},{20,3},{20,12},{20,23},{20,26},{20,27},
		{21,2},{21,12},{21,23},{21,24},{21,28},{21,29},
		{22,12},{22,24},{22,25},{22,26},{22,30},
		{23,13},{23,24},{23,27},{23,28},{23,30},
		{24,14},{24,24},{24,29},{24,30},
		{25,15},{25,18},{25,20},{25,25},{25,30},
		{26,9},{26,10},{26,11},{26,12},{26,13},{26,14},            {26,15},{26,16},{26,17},{26,18},{26,19},{26,20},{26,26},
		{27,8},{27,18},{27,20},{27,26},
		{28,9},{28,18},{28,20},{28,24},{28,25},{28,26},
		{29,10},{29,21},{29,26},{29,27},
		{30,11},{30,19},{30,21},{30,28},{30,29},
		{31,12},{31,16},{31,20},{31,21},{31,30},
		{32,12},{32,18},{32,20},{32,21},{32,25},{32,26},{32,27},{32,28},{32,30},
		{33,12},{33,18},{33,19},{33,21},{33,26},{33,29},{33,30},
		{34,12},{34,18},{34,20},{34,21},{34,25},{34,30},
		{35,12},{35,16},{35,20},{35,21},{35,22},{35,22},{35,24},{35,25},{36,26},
		{36,11},{36,19},{36,21},{36,24},{36,27},
		{37,10},{37,21},{37,25},{37,28},
		{38,9},{38,18},{38,20},{38,21},{38,26},{38,29},
		{39,8},{39,18},{39,20},{39,27},{39,30},
		{40,9},{40,10},{40,11},{40,12},{40,13},{40,14},{40,15},{40,16},{40,17},{40,18},{40,19},{40,20},{40,28},{40,30},
		{41,18},{41,20},{41,29},{41,30},
		{42,18},{42,20},
		}
	};
 GEOMETRY cat_stand_geometry =
	{
		188,
		43,30,
		{
		{9,1},{9,2},{9,3},{9,4},{9,5},
		{10,1},{10,6},{10,7},{10,8},{10,25},{10,26},{10,27},{10,28},{10,29},
		{11,2},{11,3},{11,9},{11,10},{11,11},{11,12},{11,13},{11,14},{11,15},{11,16},{11,17},{11,18},{11,25},{11,26},{11,27},{11,28},{11,29},
		{12,3},{12,4},{12,5},{12,6},{12,18},{12,19},{12,20},{12,21},{12,24},{12,30},
		{13,7},{13,8},{13,22},{13,23},{13,27},{13,28},{13,29},{13,30},
		{14,9},{14,10},{14,11},{14,23},{14,26},
		{15,12},{15,24},{15,25},
		{16,12},{16,25},{16,26},
		{17,12},{17,26},
		{18,12},{18,21},{18,27},
		{19,12},{19,22},{19,28},
		{20,12},{20,23},{20,24},{20,25},{20,29},
		{21,12},{21,23},{21,26},{21,27},{21,30},
		{22,12},{22,23},{22,24},{22,28},{22,30},
		{23,13},{23,24},{23,29},{23,30},
		{24,14},{24,24},{24,30},
		{25,15},{25,18},{25,20},{25,25},
		{26,9},{26,10},{26,11},{26,12},{26,13},{26,14},{26,15},{26,16},{26,17},{26,18},{26,19},{26,20},{26,26},
		{27,8},{27,18},{27,20},{27,26},
		{28,9},{28,18},{28,20},{28,26},
		{29,10},{29,21},{29,26},
		{30,11},{30,19},{30,21},{30,26},{30,28},{30,29},{30,30},
		{31,12},{31,16},{31,20},{31,21},{31,26},{31,30},
		{32,12},{32,18},{32,20},{32,21},{32,28},{32,29},
		{33,12},{33,18},{33,19},{33,21},{33,26},{33,29},
		{34,12},{34,18},{34,20},{34,21},{34,25},{34,26},{34,27},{34,30},
		{35,12},{35,16},{35,20},{35,21},{35,22},{35,22},{35,24},{35,25},{36,28},{36,30},
		{36,11},{36,19},{36,21},{36,29},{36,30},
		{37,10},{37,21},{37,30},
		{38,9},{38,18},{38,20},{38,21},
		{39,8},{39,18},{39,20},
		{40,9},{40,10},{40,11},{40,12},{40,13},{40,14},{40,15},{40,16},{40,17},{40,18},{40,19},{40,20},
		{41,18},{41,20},
		{42,18},{42,20},
		}
	};
	
 GEOMETRY cat_duck_geometry =
	{
		188,
		43,20,
		{
		{9,1},{9,2},{9,3},{9,4},{9,5},
		{10,1},{10,6},{10,7},{10,8},
		{11,2},{11,3},{11,9},{11,10},{11,11},{11,12},{11,13},{11,14},{11,15},{11,16},{11,17},{11,18},
		{12,3},{12,4},{12,5},{12,6},{12,18},{12,19},{12,20},{12,21},
		{13,7},{13,8},{13,22},
		{14,9},{14,10},{14,11},{14,23},
		{15,12},{15,24},
		{16,12},{16,24},
		{17,12},{17,25},
		{18,12},{18,21},{18,25},
		{19,12},{19,22},{19,25},
		{20,12},{20,23},{20,25},
		{21,12},{21,23},{21,25},
		{22,12},{22,23},{22,25},
		{23,13},{23,23},{23,25},
		{24,14},{24,24},{24,25},
		{25,15},{25,18},{25,20},{25,22},
		{26,9},{26,10},{26,11},{26,12},{26,13},{26,14},{26,15},{26,16},{26,17},{26,18},{26,19},{26,20},{26,23},
		{27,8},{27,18},{27,20},{27,24},
		{28,9},{28,18},{28,20},{28,25},
		{29,10},{29,21},{29,23},{29,25},
		{30,11},{30,19},{30,21},{30,23},{30,25},
		{31,12},{31,16},{31,20},{31,21},{31,23},{31,25},
		{32,12},{32,18},{32,20},{32,21},
		{33,12},{33,18},{33,19},{33,21},{33,24},{33,25},
		{34,12},{34,18},{34,20},{34,21},{34,24},
		{35,12},{35,16},{35,20},{35,21},{35,22},{35,25},
		{36,11},{36,19},{36,21},{36,23},{36,25},
		{37,10},{37,21},{37,23},{37,25},
		{38,9},{38,18},{38,20},{38,21},{38,23},{38,25},
		{39,8},{39,18},{39,20},{39,23},{39,25},
		{40,9},{40,10},{40,11},{40,12},{40,13},{40,14},{40,15},{40,16},{40,17},{40,18},{40,19},{40,20},{40,24},{40,25},
		{41,18},{41,20},{41,24},{41,25},
		{42,18},{42,20},
		}
	};
	
 GEOMETRY mouse_stand_geometry =
	{
		53,
		24,10,
		{
		{0,5},{0,9},
		{1,6},{1,8},
		{2,7},
		{3,6},{3,8},
		{4,5},{4,8},
		{5,4},{5,8},
		{6,4},{6,6},{6,8},
		{7,3},{7,8},{7,9},
		{8,1},{8,2},{8,9},
		{9,7},{9,8},
		{10,0},{10,4},{10,8},
		{11,0},{11,3},{11,8},
		{12,1},{12,2},{12,3},{12,8},
		{13,3},{13,8},{13,9},
		{14,3},{14,9},
		{15,3},{15,9},{15,10},
		{16,4},{16,8},
		{17,5},{17,6},{17,7},{17,8},
		{18,7},
		{19,7},
		{20,6},
		{21,5},{21,4},
		{22,3},
		{23,3},
		}
	};


 GEOMETRY mouse_run_geometry =
	{
		53,
		24,10,
		{
		{0,5},{0,9},
		{1,6},{1,8},
		{2,7},
		{3,6},{3,8},
		{4,5},{4,8},
		{5,4},{5,8},
		{6,4},{6,6},{6,8},
		{7,3},{7,8},
		{8,1},{8,2},{8,9},
		{9,7},{9,8},{9,9},
		{10,0},{10,4},{10,8},
		{11,0},{11,3},{11,8},
		{12,1},{12,2},{12,3},{12,8},
		{13,3},{13,8},
		{14,3},{14,9},
		{15,3},{15,9},{15,10},
		{16,4},{16,8},{16,9},
		{17,5},{17,6},{17,7},{17,8},
		{18,7},
		{19,7},
		{20,6},
		{21,5},{21,4},
		{22,3},
		{23,3},
		}
	};
	
GEOMETRY bird_run_geometry =
	{
		53,
		18,15,
		{
		{0,8},
		{1,7},{1,8},
		{2,6},{2,9},
		{3,5},{3,7},{3,9},
		{4,5},{4,9},
		{5,5},{5,9},
		{6,6},{6,9},
		{7,6},{7,10},
		{8,5},{8,10},
		{9,4},{9,5},{9,11},
		{10,3},{10,5},{10,12},
		{11,2},{11,5},{11,13},
		{12,1},{12,5},{12,14},{12,8},
		{13,0},{13,1},{13,2},{13,3},{13,4},{13,5},{13,9},{13,10},{13,11},{13,12},{13,13},{13,14},
		{14,4},{14,9},
		{15,4},{15,9},
		{16,3},{16,8},
		{17,3},{17,4},{17,5},{17,6},
		}
	};


GEOMETRY bird_stand_geometry =
	{
		47,
		18,15,		// samma size i bägge geometry
		{
		{0,8},
		{1,7},{1,8},
		{2,6},{2,9},
		{3,5},{3,7},{3,9},
		{4,5},{4,9},
		{5,5},{5,9},
		{6,6},{6,9},
		{7,4},{7,6},{7,10},{7,6},
		{8,3},{8,5},{8,10},
		{9,2},{9,4},{9,10},
		{10,3},{10,10},
		{11,2},{11,10},
		{12,1},{12,6},{12,7},{12,10},
		{13,2},{13,3},{13,4},{13,5},{13,9},
		{14,4},{14,9},
		{15,4},{15,8},
		{16,3},{16,7},
		{17,3},{17,4},{17,5},{17,6},
		}
	};
	
 

GEOMETRY damsugare_geometry =
	
	{
	106,
	25,19,
	{
	{0,18},{0,19},
	 {1,17},{1,19},
	 {2,17},{2,19},
	 {3,16},{3,19},
	 {4,8},{4,9},{4,10},{4,11},{4,12},{4,13},{4,14},{4,15},{4,16},{4,19},
	 {5,6},{5,7},{5,19},
	 {6,4},{6,5},{6,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{6,15},{6,16},{6,19},
	 {7,3},{7,6},{7,7},{7,16},{7,17},{7,18},{7,19},
	 {8,2},{8,4},{8,5},
	 {9,1},{9,3},
	 {10,1},{10,3},
	 {11,1},{11,3},
	 {12,0},{12,2},
	 {13,0},{13,2},{13,9},{13,10},{13,11},{13,12},{13,13},{13,16},{13,17},
	 {14,1},{14,3},{14,8},{14,14},{14,15},{14,18},
	 {15,1},{15,4},{15,5},{15,6},{15,7},{15,14},{15,19},
	 {16,2},{16,3},{16,14},{16,19},
	 {17,4},{17,5},{17,14},{17,19},
	 {18,6},{18,7},{18,15},{18,18},
	 {19,7},{19,16},{19,17},{19,19},
	 {20,7},{20,19},
	 {21,8},{21,9},{21,19},
	 {22,9},{22,19},
	 {23,10},{23,19},
	 {24,11},{24,17},{24,18},
	 {25,12},{25,13},{25,14},{25,15},{25,16},
	 
		}
	};
	
	OBJECT cat =
	{
		
		&cat_stand_geometry,
		&cat_run_geometry,
		&cat_jump_geometry,
		&cat_duck_geometry,
		0,
		0,0,
		5,START_POS_CAT,
		draw_object,
		clear_object,
		move_catobject,
		clear_all_geo,
		set_object_speed,
	};
	
OBJECT mouse =
	{
		
		&mouse_stand_geometry,
		&mouse_run_geometry,
		&cat_jump_geometry,
		&cat_duck_geometry,
		0,
		-3,0,
		129,50,
		draw_object,
		clear_object,
		move_mouseobject,
		clear_all_geo,
		set_object_speed,
	};
	
OBJECT bird =
	{
		
		&bird_stand_geometry,
		&bird_run_geometry,
		&cat_jump_geometry,
		&cat_duck_geometry,
		0,
		-3,0,
		129,10,
		draw_object,
		clear_object,
		move_mouseobject,
		clear_all_geo,
		set_object_speed,
	};

OBJECT damsugare =
	{
		
		&damsugare_geometry,
		&bird_run_geometry,
		&cat_jump_geometry,
		&cat_duck_geometry,
		0,
		-7,0,
		95,40,
		draw_object,
		clear_object,
		move_damsugare,
		clear_all_geo,
		set_object_speed,
	};