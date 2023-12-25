#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;

	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
	
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
		//[1] If user clicks on the Toolbar

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			

			switch (ClickedItemOrder)
			{
			case ITM_EXIT: return EXIT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_START_REC: return START_REC;
			case ITM_STOP_REC: return STOP_REC;
			case ITM_PLAY_REC: return PLAY_REC;	
			case ITM_SELECT: return SELECT;
			case ITM_MOVE: return MOVE;
			case ITM_CLEAR: return CLEAR;
			case ITM_DELETE: return DEL;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRCLE: return DRAW_CIRC;
			case ITM_HEXAGON: return DRAW_HEX;
			case ITM_TRIANGLE: return DRAW_TRI;
			case ITM_SQUARE: return DRAW_SQ;
			case ITM_DRAWINGCLR: return DRAW_COLOUR;
			case ITM_FILLINGCLR: return FILL_COLOUR;
			case ITM_PLAYMODE: return TO_PLAY;
			case ITM_PLAY_VOICE: return PLAY_VOICE;
			case ITM_DRAGGING_MOVE: return DRAGGING_MOVE;
			//case ITM_COLOUR: return COLOURS;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}


		

		//[3] User clicks on the status bar
		//if (y >= UI.height - UI.StatusBarHeight && y < UI.height)
			//return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_DRAWMODE : return TO_DRAW;
			case ITM_FIGURE_TYPE_AND_FILL_COLOR: return PICK_CLR_FIG;
			case ITM_FIGURE_FILL_COLOR: return PICK_CLR;
			case ITM_FIGURE_TYBE: return PICK_FIG;
			case EXIT_PLAY: return GET_EXIT_PLAY;

			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}
		
		//return TO_PLAY;	//just for now. This should be updated
	}

	// check if it is on status bar or not (whatever the mode)
	if (y >= UI.height - UI.StatusBarHeight && y < UI.height)
		return STATUS;
}
/////////////////////////////////

ActionColour Input::GetColourAction(DrawMenuItem ITM) const
{
	int x, y;

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		int Colour_Clicked = y / UI.ToolBarHeight - 1;
		int Color_clicked_X = (x / UI.MenuItemWidth);

		if (Color_clicked_X == ITM) //the click must be under colors icon
		{
			switch (Colour_Clicked)
			{
			case COL_GREEN: return GET_GREEN;
			case COL_RED: return GET_RED;
			case COL_YELLOW: return GET_YELLOW;
			case COL_BLACK: return GET_BLACK;
			case COL_BLUE: return GET_BLUE;
			case COL_ORANGE: return GET_ORANGE;

			default: break;
			}
		}
		
}

void Input::StopStoringClicks() const
{
	pWind->FlushMouseQueue();
	
}
void Input::StopStoringKeys() const
{
	pWind->FlushKeyQueue();
}

bool Input::ClickingStatus(int& x, int& y)
{
	return (pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN);
}
	
Input::~Input()
{
}