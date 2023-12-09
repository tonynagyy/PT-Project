#ifndef CTRIGLE_H
#define CTRIGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(const Point&, const Point&, const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);
	virtual double CalcArea();
	virtual void PrintInfo(Output *pOut);
};
#endif
