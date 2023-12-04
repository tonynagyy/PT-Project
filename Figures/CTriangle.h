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
};
#endif
