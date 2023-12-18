#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"


#define PI 3.141592653589793

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
	static int Count;
	int Num;

public:
	CCircle(const Point&, const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);

	virtual int Counter();

	virtual void FakeDraw(Output* pOut);

	//Calculate the area
	virtual double CalcArea();
	virtual int GetID();
	virtual int GetNum();
	virtual color GetDrawClr();
	virtual color GetFillClr();

	//Print the data of the figure on the status bar
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* clone() const override;
};

#endif