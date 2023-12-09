#include "CCircle.h"



 CCircle::CCircle(const Point &p1, const Point &p2, GfxInfo FigureGfxInfo)
	 : CFigure(FigureGfxInfo), P1(p1), P2(p2){
 }
 void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	 pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}

 bool CCircle::InFigure(int x, int y)
 {
	 // Check if the point is in or not by comparing the radius with distance between the point and the center 
	 return (DEST(P1.x, P1.y, x, y) < DEST(P1.x, P1.y, P2.x, P2.y));
 }

 double CCircle::CalcArea()
 {
	 // Calculate the area of the circle 
	 double r = CIRCLE_RADIUS(DELTA(P1.x, P2.x), DELTA(P1.y, P2.y));
	 return PI * r * r;
 }

 void CCircle::PrintInfo(Output* pOut)
 {
	 pOut->PrintMessage("Figure: Circle     Area:");
 }



