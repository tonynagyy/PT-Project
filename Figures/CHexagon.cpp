#include "CHexagon.h"

CHexagon::CHexagon(const Point&p1,  GfxInfo FigureGfxInfo)
	 : CFigure(FigureGfxInfo) , center(p1) {
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}
