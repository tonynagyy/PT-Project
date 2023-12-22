#ifndef CHEXA_H
#define CHEXA_H

#include "CFigure.h"



class CHexagon : public CFigure
{
private:
	Point center;
	//static int Count;
	//int Num;
	
public:
	CHexagon() = default;
	CHexagon(const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);
	virtual double CalcArea();
	virtual void PrintInfo(Output *pOut);
	//virtual int Counter();
	virtual void FakeDraw(Output* pOut);
	virtual int GetID();
	//virtual int GetNum();
	//virtual void DecNum();
	//virtual void IncNum();
	virtual color GetDrawClr();
	virtual color GetFillClr();
	void Save(ofstream &outFile) override;
	void Load(ifstream &inFile) override;


	virtual CFigure* clone() const override;
	virtual void move(double x, double y) override;
};
#endif
