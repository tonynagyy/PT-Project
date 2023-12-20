#ifndef CHEXA_H
#define CHEXA_H

#include "CFigure.h"



class CHexagon : public CFigure
{
private:
	Point center;
	static int Count;
	int Num;
	
public:
	CHexagon(const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);
	virtual double CalcArea();
	virtual void PrintInfo(Output *pOut);
	virtual int Counter();
	virtual void FakeDraw(Output* pOut);
	virtual int GetID();
	virtual int GetNum();
	virtual color GetDrawClr();
	virtual color GetFillClr();
	void Save(ofstream &outFile) override;


	virtual CFigure* clone() const override;
};
#endif
