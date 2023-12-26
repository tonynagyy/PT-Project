#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

#define HEXA_RADIUS 80
#define HEX_CALC  ((sqrt(3) / 2) * HEXA_RADIUS)
#define HALF_SQUARE_LENGTH 50 
#define CIRCLE_RADIUS(X, Y) (sqrt((X) * (X) + (Y) * (Y)))

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateColourMenu(DrawMenuItem ITM) const; // creats a colour menu 
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const; //Clears the tool bar
	//void ClearColourMenu() const;

	// -- Figures Drawing functions
	void DrawRect(const Point &P1,const  Point &P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo RectGfxInfo, bool selected = false, int L = 0) const;  //Draw a square
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a tiangle
	void DrawHexagon(Point P1, GfxInfo RectGfxInfo, bool selected, int L = 0) const;  //Draw a hexagon
	void DrawCircle(const  Point &P1,const  Point &P2, GfxInfo RectGfxInfo, bool selected) const;
	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	void setCrntDrawColor(color c);
	void setCrntFillColor(color c);
	int getCrntPenWidth() const;		//get current pen width
	color GetColour(Input* pIn, Output* pOut, DrawMenuItem ITM) const;
	~Output();
};

#endif