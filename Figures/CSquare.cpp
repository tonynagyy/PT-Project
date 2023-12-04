#include "CSquare.h"

CSquare::CSquare(const Point&p1, GfxInfo FigureGfxInfo)
       : CFigure(FigureGfxInfo), center(p1) {
}

void CSquare::Draw(Output* pOut) const
{
    //Call Output::DrawSquare to draw a square on the screen	
    pOut->DrawSquare(center, FigGfxInfo, Selected);
}
