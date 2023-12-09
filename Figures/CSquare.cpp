#include "CSquare.h"

CSquare::CSquare(const Point&p1, GfxInfo FigureGfxInfo)
       : CFigure(FigureGfxInfo), center(p1) {
}

void CSquare::Draw(Output* pOut) const
{
    //Call Output::DrawSquare to draw a square on the screen	
    pOut->DrawSquare(center, FigGfxInfo, Selected);
}

bool CSquare::InFigure(int x, int y)
{
    //Check if the point in the region of the square or not
    return (DEST(center.x, center.y, x, y) < HALF_SQUARE_LENGTH);
}

double CSquare::CalcArea()
{
    // Calculate the area of the square
    return 4 * HALF_SQUARE_LENGTH * HALF_SQUARE_LENGTH;
}

void CSquare::PrintInfo(Output* pOut)
{
    pOut->PrintMessage("Figure: Square    ");
}
