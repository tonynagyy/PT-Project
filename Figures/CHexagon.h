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

};
#endif
