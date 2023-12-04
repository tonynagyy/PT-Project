#ifndef CSquare_H
#define CSquare_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point center;

public:
	CSquare(const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

};
#endif
