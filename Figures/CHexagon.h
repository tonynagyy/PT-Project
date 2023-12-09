#ifndef CHEXA_H
#define CHEXA_H

#include "CFigure.h"



class CHexagon : public CFigure
{
private:
	Point center;
	
public:
	CHexagon(const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);
	virtual double CalcArea();
	virtual void PrintInfo(Output *pOut);

};
#endif
