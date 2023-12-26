#ifndef CSquare_H
#define CSquare_H

#include "CFigure.h"



class CSquare : public CFigure
{
	private:
		Point center;
		int Modified_Length = 0;
	public:
		CSquare(const Point&, GfxInfo FigureGfxInfo);
		CSquare() = default;
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
		virtual void move(double& x, double& y, bool b = true);
		virtual void Resize(int x, int y, bool& Valid, int c = 0);
		void Load(ifstream& Infile) override;

		virtual CFigure* clone() const override;
};
#endif
