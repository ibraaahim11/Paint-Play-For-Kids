#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,//Draw Rectangle
	///TODO: Add the other action types of the two modes
	//=====================================================//Draw Mode Items
	DRAW_SQR, DRAW_TRI, DRAW_HEX, DRAW_CIR,
	I_BLACK, I_YELLOW, I_ORANGE, I_RED, I_GREEN, I_BLUE,
	SELECT, BORDER, FILL, COPY, CUT, PASTE,
	R14, R12, R2, R4,                                      //OMAR
	FORWARD, BACKWARD, I_DELETE, CLEAR,
	SAVE, LOAD, D_SOUND, TO_PLAY, EXIT,
	//=====================================================//Play Mode
	FIG_TYPE, FIG_COLOR, BOTH, P_SOUND, TO_DRAW,                        //OMAR
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,		//A click on the status bar
	//TO_DRAW,		//Switch interface to Draw mode
	//TO_PLAY,	//Switch interface to Play mode
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
};

#endif