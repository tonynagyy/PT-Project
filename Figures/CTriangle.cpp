#include "CTriangle.h"

CTriangle::CTriangle(const Point&p1, const Point&p2, const Point&p3, GfxInfo FigureGfxInfo)
	: CFigure(FigureGfxInfo) , P1(p1) , P2(p2) , P3(p3) {
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(P1 , P2 , P3 , FigGfxInfo, Selected);
}
