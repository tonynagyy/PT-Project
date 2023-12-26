#ifndef CTRIGLE_H
#define CTRIGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;
	//static int Count;
	//int Num;

public:
	CTriangle() = default;
	CTriangle(const Point&, const Point&, const Point&, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool InFigure(int x, int y);
	virtual double CalcArea();
	void Switch();
	virtual void PrintInfo(Output *pOut);

	virtual int GetID();
	virtual bool IsDrawn();
	virtual Point Getcenter();
	virtual color GetDrawClr();
	virtual color GetFillClr();

	void Save(ofstream &outFile) override;
	void Load(ifstream &Infile) override;

	// make clone copy constructor
	virtual CFigure* clone() const override;
	virtual void move(double& x, double& y, bool b = true) override;
	virtual void Resize(int x, int y, bool& Valid, int c);
	virtual int SelectCorner(int x, int y);
};
#endif
