#include "CTriangle.h"

//int CTriangle::Count = 0;

CTriangle::CTriangle(const Point& p1, const Point& p2, const Point& p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), P1(p1), P2(p2), P3(p3)
{
	Identifier = 1;
	if (CalcArea() && IsDrawn())
	{
		Count++;
		ID = Count;
	}

}

void CTriangle::Draw(Output* pOut) const
{
	if (isDrawn)
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
	string S = "Triangle ID: ";
	string S1 = "  Figure: Triangle    Area: ";
	string S2 = "  Center: (";
	string S3 = " , ";
	string S4 = ")   Is Filled :  ";
	string S5 = " False";
	string S6 = " True";
	if (FigGfxInfo.isFilled)
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string((P1.x + P2.x + P3.x) / 3) + S3 + to_string((P1.y + P2.y + P3.y) / 3) + S4 + S6;
		pOut->PrintMessage(msg);
	}
	else
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string((P1.x + P2.x + P3.x) / 3) + S3 + to_string((P1.y + P2.y + P3.y) / 3) + S4 + S5;
		pOut->PrintMessage(msg);
	}
	

}

/*
int CTriangle::Counter()
{
	return Count;
}
*/

int CTriangle::GetID()
{
	return ID;
}
bool CTriangle::IsDrawn()
{
	isDrawn = !(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P3.y < UI.ToolBarHeight || P3.y > UI.height - UI.StatusBarHeight);
	return isDrawn;
}
Point CTriangle::Getcenter()
{
	Point center;
	center.x = (P1.x + P2.x + P3.x) / 3;
	center.y = (P1.y + P2.y + P3.y) / 3;
	return center;
}
/*
int CTriangle::GetNum()
{
	return Num;
}

void CTriangle::IncNum()
{
	Num++;
}

void CTriangle::DecNum()
{
	Num--;
}
*/
color CTriangle::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CTriangle::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CTriangle::Save(ofstream& outFile) {
//	TRIANG 3 10 20 70 30 220 190 BLACK RED
	outFile << "TRIANG\t" << ID << "\t" << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t" << P3.x << "\t" << P3.y << "\t";
	outFile << FigGfxInfo.DrawClr << "\t";
	outFile << FigGfxInfo.FillClr << endl;
}

void CTriangle::Load(ifstream& Infile) {
	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;
	Infile >> FigGfxInfo.DrawClr;
	Infile >> FigGfxInfo.FillClr;
}


CFigure* CTriangle::clone() const
{
	return new CTriangle(*this);
}
 
void CTriangle::move(double x, double y)
{
	double centerx = (P1.x + P2.x + P3.x) / 3.0;
	double centery = (P1.y + P2.y + P3.y) / 3.0;
	double shiftx = x - centerx;
	double shifty = y - centery;
	P1.x = P1.x + shiftx;
	P2.x = P2.x + shiftx;
	P3.x = P3.x + shiftx;
	P1.y = P1.y + shifty;
	P2.y = P2.y + shifty;
	P3.y = P3.y + shifty;
}
