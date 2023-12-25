#ifndef CSquare_H
#define CSquare_H

#include "CFigure.h"



class CSquare : public CFigure
{
	private:
		Point center;
	public:
		CSquare(const Point&, GfxInfo FigureGfxInfo);
		CSquare() = default;
		//CSquare();
		void Draw(Output* pOut) const;
		virtual bool InFigure(int x, int y);
		virtual double CalcArea();
		virtual void PrintInfo(Output* pOut);

		virtual bool IsDrawn();

		virtual int GetID();

		virtual Point Getcenter();
		virtual color GetDrawClr();
		virtual color GetFillClr();

		void Save(ofstream& outFile) override;
		virtual void move(double x, double y);
		void Load(ifstream& Infile) override;

		virtual CFigure* clone() const override;
};
#endif
