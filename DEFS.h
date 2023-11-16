#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	EXIT,
	SAVE,
	LOAD,
	UNDO,
	REDO,
	START_REC,
	STOP_REC,
	PLAY_REC,
	SELECT,
	MOVE,
	CLEAR,
	DEL,  // delete item ----> Note: there is a func called delete so we wrote it as "DEL"
	DRAW_RECT, //Draw Rectangle
	DRAW_CIRC, // Draw Circle
	DRAW_HEX, // Draw hexagon
	DRAW_TRI, // Draw triangle
	DRAW_SQ, // Draw sqaure 
	HIGH_FRAME, // highlighted the frame of the figure 
	FILL, // fill the figure
	TO_PLAY,//Switch interface to Play mode
	COLOURS,
	TO_DRAW,		//Switch interface to Draw mode
	F1,
	F2,
	F3,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif