#include "CCircle.h"



 CCircle::CCircle(const Point&p1, const Point&p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), P1(p1), P2(p1){



 }
 void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	 pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}

