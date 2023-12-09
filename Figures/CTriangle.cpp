#include "CTriangle.h"

CTriangle::CTriangle(const Point&p1, const Point&p2, const Point&p3, GfxInfo FigureGfxInfo)
	: CFigure(FigureGfxInfo) , P1(p1) , P2(p2) , P3(p3) {
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
	pOut->PrintMessage("Figure: Triangle ");

}
