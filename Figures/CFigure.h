#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include "..\helper.h"

#define DEST(X1, Y1, X2, Y2) (sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2)))
#define DELTA(X1, X2) (abs(X1 - X2))


//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static color DrwClr;
	static color FlClr;
	bool hidden;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool InFigure(int x, int y) = 0; // check if the point clicked is in the figure or not
	void Sethidden(bool hd);
	bool IfHidden();


	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void FakeDraw(Output* pOut) = 0;
	virtual int GetID() = 0;
	virtual int GetNum() = 0;
	virtual color GetDrawClr();
	virtual color GetFillClr();

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	
	// Calculate an area of a triangle using its 3 sides
	// Its use is to check if the point is in or not 
	float Tri_Area(int X1, int Y1, int X2, int Y2, int X3, int Y3);


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream& outFile);	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) ;	//Load the figure parameters to the file
	virtual int Counter() = 0;
	virtual double CalcArea() = 0;
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	virtual CFigure* clone() const = 0;
};

#endif