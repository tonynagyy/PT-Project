#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"


#define PI 3.141592653589793
#define CIRCLE_RADIUS(X, Y) (sqrt((X) * (X) + (Y) * (Y)))

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
public:
	CCircle(const Point&, const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);


	//Calculate the area
	virtual double CalcArea();

	//Print the data of the figure on the status bar
	virtual void PrintInfo(Output* pOut);
};

#endif