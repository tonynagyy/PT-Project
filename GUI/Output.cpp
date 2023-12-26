#include "Output.h"


int ciell(double x)
{
	int y = (int)x;
	if (x > y)
		return y + 1;
	else
		return y;
}
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1380;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 59;


	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = SNOW;	//Filling color
	UI.MsgColor = SNOW;		//Messages color
	UI.BkGrndColor = SNOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = BLACK;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}



Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.BkGrndColor, 5);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();

	UI.InterfaceMode = MODE_DRAW;
	string MenuItemImages[DRAW_ITM_COUNT];

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_clear.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	MenuItemImages[ITM_DRAWINGCLR] = "images\\MenuItems\\Menu_drawingclr.jpg";
	MenuItemImages[ITM_FILLINGCLR] = "images\\MenuItems\\Menu_fillingclr.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_load.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_move.jpg";
	MenuItemImages[ITM_DRAGGING_MOVE] = "images\\MenuItems\\Menu_Dragging.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";
	MenuItemImages[ITM_PLAY_REC] = "images\\MenuItems\\Menu_playrec.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_redo.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_select.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_square.jpg";
	MenuItemImages[ITM_START_REC] = "images\\MenuItems\\Menu_startrec.jpg";
	MenuItemImages[ITM_STOP_REC] = "images\\MenuItems\\Menu_stoprec.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_undo.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_playmode.jpg";
	MenuItemImages[ITM_PLAY_VOICE] = "images\\MenuItems\\Menu_playvoice.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	
	//MenuItemImages[ITM_COLOUR] = "images\\MenuItems\\Menu_colors.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++) {
		pWind->DrawImage(MenuItemImages[i], (i * UI.MenuItemWidth) + 5 , 5, UI.MenuItemWidth - 10, UI.ToolBarHeight - 10);
		//pWind->SetPen(DARKRED, 3);
		//pWind->DrawLine(UI.MenuItemWidth * i, 0, UI.MenuItemWidth * i, UI.ToolBarHeight);
	}
	//Draw a line under the toolbar
	pWind->SetPen(DARKRED, 5);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages2[PLAY_ITM_COUNT];

	MenuItemImages2[ITM_DRAWMODE] = "images\\MenuItems\\Menu_drawmode.jpg";
	MenuItemImages2[ITM_FIGURE_FILL_COLOR] = "images\\MenuItems\\Menu_figurefillcolor.jpg";
	MenuItemImages2[ITM_FIGURE_TYPE_AND_FILL_COLOR] = "images\\MenuItems\\Menu_figuretybeandfillcolor.jpg";
	MenuItemImages2[ITM_FIGURE_TYBE] = "images\\MenuItems\\Menu_figuretype.jpg";
	MenuItemImages2[EXIT_PLAY] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColourMenu(DrawMenuItem ITM) const 
{
	

	string MenuColourImages[COLOUR_ITM_COUNT];

	MenuColourImages[COL_RED] = "images\\MenuItems\\Menu_red.jpg";
	MenuColourImages[COL_GREEN] = "images\\MenuItems\\Menu_green.jpg";
	MenuColourImages[COL_BLUE] = "images\\MenuItems\\Menu_blue.jpg";
	MenuColourImages[COL_BLACK] = "images\\MenuItems\\Menu_black.jpg";
	MenuColourImages[COL_ORANGE] = "images\\MenuItems\\Menu_orange.jpg";
	MenuColourImages[COL_YELLOW] = "images\\MenuItems\\Menu_yellow.jpg";
	
	for (int i = 0; i < COLOUR_ITM_COUNT; i++)
		pWind->DrawImage(MenuColourImages[i], (ITM) * UI.MenuItemWidth, (i + 1) * UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);
}

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	Sleep(1);
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
} 
void Output::setCrntDrawColor(color c) {
	UI.DrawColor = c;
}
void Output::setCrntFillColor(color c) {
	UI.FillColor = c;
}
//////////////////////////////////////////////////////////////////////////////////////////


int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

color Output::GetColour(Input* pIn, Output* pOut, DrawMenuItem ITM) const
{
	pOut->CreateColourMenu(ITM);
	ActionColour ActCol;
	ActCol = pIn->GetColourAction(ITM);

	switch (ActCol)
	{
	case GET_GREEN:
		pOut->PrintMessage("Action: a click on Green Colour Icon, Click anywhere");
		return GREEN;
		break;
	case GET_BLACK:
		pOut->PrintMessage("Action: a click on black Colour Icon, Click anywhere");
		return BLACK;
		break;
	case GET_RED:
		pOut->PrintMessage("Action: a click on red Colour Icon, Click anywhere");
		return RED;
		break;
	case GET_BLUE:
		pOut->PrintMessage("Action: a click on blue Colour Icon, Click anywhere");
		return BLUE;
		break;
	case GET_ORANGE:
		pOut->PrintMessage("Action: a click on orange Colour Icon, Click anywhere");
		return ORANGE;
		break;
	case GET_YELLOW:
		pOut->PrintMessage("Action: a click on yellow Colour Icon, Click anywhere");
		return YELLOW;
		break;
	default:
		break;
	}
	return NULL;
}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

//DRAW RECTANGLE FUNCTION
void Output::DrawRect(const Point &P1, const Point &P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

//DRAWING SQUARE FUNCTION
void Output::DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected, int L) const
{
	int centerX = 0, centerY = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	color DrawingClr;
	drawstyle style;

	centerX = P1.x;
	centerY = P1.y;
	if (!L)
	{
		x1 = centerX - HALF_SQUARE_LENGTH;
		y1 = centerY - HALF_SQUARE_LENGTH;
		x2 = centerX + HALF_SQUARE_LENGTH;
		y2 = centerY + HALF_SQUARE_LENGTH;
	}
	else
	{
		x1 = centerX - L;
		y1 = centerY - L;
		x2 = centerX + L;
		y2 = centerY + L;
	}
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(x1, y1, x2, y2, style);
}

//DRAWING TRIANGLE FUNCTION
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	int verticsOneX, verticsOneY, verticsTwoX, verticsTwoY, verticsThreeX, verticsThreeY;
	color DrawingClr;
	drawstyle style;

	verticsOneX = P1.x;
	verticsOneY = P1.y;
	verticsTwoX = P2.x;
	verticsTwoY = P2.y;
	verticsThreeX = P3.x;
	verticsThreeY = P3.y;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(verticsOneX, verticsOneY, verticsTwoX, verticsTwoY, verticsThreeX, verticsThreeY, style);
}

//DRAW HEXAGON FUNCTION
void Output::DrawHexagon(Point P1, GfxInfo RectGfxInfo, bool selected, int L) const
{
	color DrawingClr;
	drawstyle style;
	int xVertices[6] = {P1.x - HEXA_RADIUS, P1.x - HEXA_RADIUS / 2, P1.x + HEXA_RADIUS / 2, P1.x + HEXA_RADIUS, P1.x + HEXA_RADIUS /2, P1.x - HEXA_RADIUS / 2};
	int yVertices[6] = {P1.y, ceil(P1.y + HEX_CALC), ceil(P1.y + HEX_CALC), P1.y, ceil(P1.y - HEX_CALC), ceil(P1.y - HEX_CALC)};

	int L_CALC = ((sqrt(3) / 2) * L);
	int xLVertices[6] = { P1.x - L, P1.x - L / 2, P1.x + L / 2, P1.x + L, P1.x + L / 2, P1.x - L / 2 };
	int yLVertices[6] = { P1.y, ceil(P1.y + L_CALC), ceil(P1.y + L_CALC), P1.y, ceil(P1.y - L_CALC), ceil(P1.y - L_CALC) };
	
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if(!L)
		pWind->DrawPolygon(xVertices, yVertices, 6, style);
	else
		pWind->DrawPolygon(xLVertices, yLVertices, 6, style);
}

/*
* DrawCircle - Draw a circle with a given center and radius
* @P1 - The center of the circle
* @P2 - A point on the circle
* @RectGfxInfo - The graphics info of the circle
* @selected - Whether the circle is selected or not
* @Description - This function draws a circle with a given center and radius
* Return void 
*/
void Output::DrawCircle(const Point &P1,const Point &P2, GfxInfo RectGfxInfo, bool selected) const
{
	int deltaX = P2.x - P1.x;
	int deltaY = P2.y - P1.y;
	int radius = CIRCLE_RADIUS(deltaX, deltaY);
	color DrawingClr;
	drawstyle style;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
