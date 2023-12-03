#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
public:
	CCircle(const Point&, const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif