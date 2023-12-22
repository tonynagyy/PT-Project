#include "CRectangle.h"
#include "../Actions/AddRectAction.h"
#include "CCircle.h"

//int CRectangle::Count = 0;

 CRectangle::CRectangle(const Point &P1, const Point &P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), Corner1(P1), Corner2(P2)
 {
	Identifier = 3;
  	Count++;
	ID = Count;
 }
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::InFigure(int x, int y)
{
	// Check if the point in the region of the rectangle or not
	return (DELTA(Corner1.x, Corner2.x) == DELTA(Corner1.x, x) + DELTA(Corner2.x, x) && DELTA(Corner1.y, Corner2.y) == DELTA(Corner1.y, y) + DELTA(Corner2.y, y));
}

double CRectangle::CalcArea()
{
	// Calculate the area of the rectangle
	return DELTA(Corner1.x, Corner2.x) * DELTA(Corner1.y,Corner2.y);
}

void CRectangle::PrintInfo(Output* pOut)
{
	string msg;

	string S = "Rectangle ID: ";
	string S1 = "  Figure: Rectangle    Area: ";
	string S2 = "  Center: (";
	string S3 = " , ";
	string S4 = ")   Is Filled :  ";
	string S5 = " False";
	string S6 = " True";
	if (FigGfxInfo.isFilled)
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string((Corner1.x + Corner2.x) / 2) + S3 + to_string((Corner1.y + Corner2.y) / 2) + S4 + S6;
		pOut->PrintMessage(msg);
	}
	else
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string((Corner1.x + Corner2.x) / 2) + S3 + to_string((Corner1.y + Corner2.y) / 2) + S4 + S5;
		pOut->PrintMessage(msg);
	}
}


void CRectangle::FakeDraw(Output* pOut)
{
	FigGfxInfo.DrawClr = LIGHTGOLDENRODYELLOW;
	Draw(pOut);
	FigGfxInfo.DrawClr = BLUE;
}

int CRectangle::GetID()
{
	return ID;
}


Point CRectangle::Getcenter()
{
	Point center;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	return center;
}

color CRectangle::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CRectangle::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CRectangle::Save(ofstream& outFile) {
	//RECT 1 100 200 17 30 BLUE RED
	outFile << "RECT\t" << ID << "\t";
	outFile << Corner1.x << "\t" << Corner1.y << "\t";
	outFile << Corner2.x << "\t" << Corner2.y << "\t";
	//GfxInfo FigGfxInfo;	//Figure graphis info
	outFile << FigGfxInfo.DrawClr << "\t";
	outFile << FigGfxInfo.FillClr << "\t";
	outFile << endl;
}

void CRectangle::Load(ifstream& Infile)
{
		//RECT 1 100 200 17 30 BLUE RED
	Infile >> ID;
	Infile >> Corner1.x >> Corner1.y;
	Infile >> Corner2.x >> Corner2.y;
	Infile >> FigGfxInfo.DrawClr;
	Infile >> FigGfxInfo.FillClr;
}

CFigure *CRectangle::clone() const
{
	return new CRectangle(*this);
}

void CRectangle::move(double x, double y)
{
	double centerx = (Corner1.x + Corner2.x) / 2.0;
	double centery = (Corner1.y + Corner2.y) / 2.0;
	double shiftx = x - centerx;
	double shifty = y - centery;
	Corner1.x = Corner1.x + shiftx;
	Corner2.x = Corner2.x + shiftx;
	Corner1.y = Corner1.y + shifty;
	Corner2.y = Corner2.y + shifty;


}
