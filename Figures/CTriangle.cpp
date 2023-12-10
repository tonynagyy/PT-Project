#include "CTriangle.h"

int CTriangle::Count = 0;

CTriangle::CTriangle(const Point&p1, const Point&p2, const Point&p3, GfxInfo FigureGfxInfo)	: CFigure(FigureGfxInfo) , P1(p1) , P2(p2) , P3(p3)
{
	ID = 1;
	Count++;
	Num = Count;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(P1 , P2 , P3 , FigGfxInfo, Selected);
}

bool CTriangle::InFigure(int x, int y)
{
	// Check if the point is in or not by dividing the base triangle into 3 small trangles 
	// If the point is in so the total area of the 3 small triangles will be equal to the base one
	float A1 = Tri_Area(P1.x, P1.y, P2.x, P2.y, x, y);
	float A2 = Tri_Area(P1.x, P1.y, x, y, P3.x, P3.y);
	float A3 = Tri_Area(x, y, P2.x, P2.y, P3.x, P3.y);
	
	return (double(CalcArea()) == (A1 + A2 + A3));
}

double CTriangle::CalcArea()
{
	return Tri_Area(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string S = "Triangle number: ";
	string S1 = "  Figure: Triangle    Area: ";
	string S2 = "  Center: (";
	string S3 = " , ";
	string S4 = ")   Is Filled :  ";
	string S5 = " False";
	string S6 = " True";
	if (FigGfxInfo.isFilled)
	{
		string msg = S + to_string(Num) + S1 + to_string(CalcArea()) + S2 + to_string((P1.x + P2.x + P3.x) / 3) + S3 + to_string((P1.y + P2.y + P3.y) / 3) + S4 + S6;
		pOut->PrintMessage(msg);
	}
	else
	{
		string msg = S + to_string(Num) + S1 + to_string(CalcArea()) + S2 + to_string((P1.x + P2.x + P3.x) / 3) + S3 + to_string((P1.y + P2.y + P3.y) / 3) + S4 + S5;
		pOut->PrintMessage(msg);
	}
	

}

int CTriangle::Counter()
{
	return Count;
}

void CTriangle::FakeDraw(Output* pOut)
{
	FigGfxInfo.DrawClr = LIGHTGOLDENRODYELLOW;
	Draw(pOut);
	FigGfxInfo.DrawClr = BLUE;
}

int CTriangle::GetID()
{
	return ID;
}
