#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"


class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	//static int Count;
	//static int Num;

public:
	CRectangle(const Point &,const Point &, GfxInfo FigureGfxInfo );
	CRectangle() = default;

	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);

	virtual double CalcArea();
	virtual void PrintInfo(Output* pOut);
	
	virtual bool IsDrawn();

	virtual int GetID();
	
	virtual Point Getcenter();
	virtual color GetDrawClr();
	virtual color GetFillClr();

	void Save(ofstream &outFile) override;
	void Load(ifstream &Infile) override;
	
	virtual CFigure* clone() const override;
	virtual void move(double x, double y) override;
	
};
//int CRectangle::Num = 0;
#endif