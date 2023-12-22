#ifndef CSquare_H
#define CSquare_H

#include "CFigure.h"



class CSquare : public CFigure
{
private:
	Point center;
	//static int Count;
	//int Num;

public:
	CSquare(const Point&, GfxInfo FigureGfxInfo);
	//CSquare() = default;
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);
	virtual double CalcArea();
	virtual void PrintInfo(Output *pOut);
	//virtual int Counter();
	virtual void FakeDraw(Output* pOut);
	virtual int GetID();
	//virtual int GetNum();
	//virtual void IncNum();
	//virtual void DecNum();
	virtual color GetDrawClr();
	virtual color GetFillClr();
	void Save(ofstream &outFile) override;
	virtual void move(double x, double y);
	void Load(ifstream &Infile) override;

	virtual CFigure *clone() const override;
};
#endif
