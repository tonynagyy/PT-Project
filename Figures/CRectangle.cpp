#include "CRectangle.h"

int CRectangle::Count = 0;

 CRectangle::CRectangle(const Point &P1, const Point &P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), Corner1(P1), Corner2(P2)
 {
	 ID = 3;
  	Count++;
	Num = Count;
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

	string S = "Rectangle number: ";
	string S1 = "  Figure: Rectangle    Area: ";
	string S2 = "  Center: (";
	string S3 = " , ";
	string S4 = ")   Is Filled :  ";
	string S5 = " False";
	string S6 = " True";
	if (FigGfxInfo.isFilled)
	{
		string msg = S + to_string(Num) + S1 + to_string(CalcArea()) + S2 + to_string((Corner1.x + Corner2.x) / 2) + S3 + to_string((Corner1.y + Corner2.y) / 2) + S4 + S6;
		pOut->PrintMessage(msg);
	}
	else
	{
		string msg = S + to_string(Num) + S1 + to_string(CalcArea()) + S2 + to_string((Corner1.x + Corner2.x) / 2) + S3 + to_string((Corner1.y + Corner2.y) / 2) + S4 + S5;
		pOut->PrintMessage(msg);
	}
}

int CRectangle::Counter()
{
	return Count;
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
