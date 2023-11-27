#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PLAYMODE,
	ITM_START_REC,
	ITM_STOP_REC,
	ITM_PLAY_REC,
	ITM_SELECT,
	ITM_MOVE,
	ITM_CLEAR,
	ITM_DELETE,
	ITM_RECT,
	ITM_CIRCLE,
	ITM_HEXAGON,
	ITM_TRIANGLE,
	ITM_SQUARE,
	ITM_UNDO,
	ITM_REDO,
	ITM_SAVE,
	ITM_LOAD,
	ITM_EXIT,//Exit item
	ITM_DRAWINGCLR,
	ITM_FILLINGCLR,
	ITM_COLOUR,
	DRAW_ITM_COUNT,
	//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_DRAWMODE = 0,
	ITM_FIGURE_TYPE_AND_FILL_COLOR,
	ITM_FIGURE_FILL_COLOR,
	ITM_FIGURE_TYBE,
	EXIT_PLAY, 
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum ColourMenuItem
{
	COL_RED,
	COL_GREEN,
	COL_BLUE,
	COL_YELLOW,
	COL_BLACK,
	COL_ORANGE,
	COLOUR_ITM_COUNT
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif