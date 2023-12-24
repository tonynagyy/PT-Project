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

	virtual int GetID();
	virtual bool IsDrawn();
	
	virtual Point Getcenter();
	virtual color GetDrawClr();
	virtual color GetFillClr();


	virtual void move(double x, double y) override;

	void Save(ofstream &outFile) override;
	void Load(ifstream &inFile) override;


	CFigure* clone() const override;
};
#endif
