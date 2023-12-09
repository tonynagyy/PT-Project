#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(const Point &,const Point &, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);

	virtual double CalcArea();
	virtual void PrintInfo(Output* pOut);
};

#endif