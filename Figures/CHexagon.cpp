#include "CHexagon.h"

CHexagon::CHexagon(const Point&p1,  GfxInfo FigureGfxInfo)
	 : CFigure(FigureGfxInfo) , center(p1) {
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

bool CHexagon::InFigure(int x, int y)
{

	// Getting the coordinates of the 6 point of the hexagon
	int X[6] = { center.x - HEXA_RADIUS, center.x - HEXA_RADIUS / 2, center.x + HEXA_RADIUS / 2, center.x + HEXA_RADIUS, center.x + HEXA_RADIUS / 2, center.x - HEXA_RADIUS / 2 };
	int Y[6] = { center.y, ceil(center.y + HEX_CALC), ceil(center.y + HEX_CALC), center.y, ceil(center.y - HEX_CALC), ceil(center.y - HEX_CALC) };

	// Dividing the hexagon into rectangle at the center and small triangles 
	// if the total area of them is equal to the area of the hexagon so the point is in 


	// Dividing the first triangle int 3 small triangles 
	// If the total area of them is equal to the base one so the point is in
	float A = Tri_Area(X[0], Y[0], X[1], Y[1], X[5], Y[5]);
	float A1 = Tri_Area(X[1], Y[1], X[5], Y[5], x, y);
	float A2 = Tri_Area(X[0], Y[0], X[1], Y[1], x, y);
	float A3 = Tri_Area(X[0], Y[0], X[5], Y[5], x, y);


	// Dividing the second triangle int 3 small triangles 
	// If the total area of them is equal to the base one so the point is in
	float S = Tri_Area(X[2], Y[2], X[3], Y[3], X[4], Y[4]);
	float S1 = Tri_Area(X[3], Y[3], X[2], Y[2], x, y);
	float S2 = Tri_Area(X[3], Y[3], X[4], Y[4], x, y);
	float S3 = Tri_Area(X[2], Y[2], X[4], Y[4], x, y);

	// Check if the point on the region of the rectangle or not
	if ( DELTA(X[1], x) + DELTA(X[2], x) == DELTA(X[1], X[2]) && (DELTA(Y[1], y) + DELTA(Y[5], y) == DELTA(Y[1], Y[5]) ) ) 
		return true;

	//Check if it on the 2 base triangles
	else if (A == A1 + A2 + A3)
		return true;
	else if (S == S1 + S2 + S3)
		return true;
	else
		return false;
}

double CHexagon::CalcArea()
{
	// Calculate the area of the hexagon
	return 1.5 * sqrt(3) * HEXA_RADIUS;
}

void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure: Hexagon");
}
