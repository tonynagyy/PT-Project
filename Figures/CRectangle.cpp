#include "CRectangle.h"

CRectangle::CRectangle(const Point &P1, const Point &P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo), Corner1(P1), Corner2(P2){
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
	pOut->PrintMessage("Figure: Rectangle  ");
}
