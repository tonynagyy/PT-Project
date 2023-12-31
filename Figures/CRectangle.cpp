#include "CRectangle.h"
#include "../Actions/AddRectAction.h"
#include "CCircle.h"

//int CRectangle::Count = 0;

CRectangle::CRectangle(const Point& P1, const Point& P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), Corner1(P1), Corner2(P2)
{
	Identifier = 3;
	if (CalcArea() && IsDrawn())
	{
		Count++;
		ID = Count;
	}
}
	

void CRectangle::Draw(Output* pOut) const
{
	if (isDrawn)
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
	string msg;

	string S = "Rectangle ID: ";
	string S1 = "  Figure: Rectangle    Area: ";
	string S2 = "  Center: (";
	string S3 = " , ";
	string S4 = ")   Is Filled :  ";
	string S5 = " False";
	string S6 = " True";
	if (FigGfxInfo.isFilled)
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string((Corner1.x + Corner2.x) / 2) + S3 + to_string((Corner1.y + Corner2.y) / 2) + S4 + S6;
		pOut->PrintMessage(msg);
	}
	else
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string((Corner1.x + Corner2.x) / 2) + S3 + to_string((Corner1.y + Corner2.y) / 2) + S4 + S5;
		pOut->PrintMessage(msg);
	}
}

bool CRectangle::IsDrawn()
{
	isDrawn = !(Corner1.y < UI.ToolBarHeight || Corner1.y > UI.height - UI.StatusBarHeight || Corner2.y < UI.ToolBarHeight || Corner2.y > UI.height - UI.StatusBarHeight);
	return isDrawn;
}


int CRectangle::GetID()
{
	return ID;
}


Point CRectangle::Getcenter()
{
	Point center;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	return center;
}

color CRectangle::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CRectangle::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CRectangle::Save(ofstream& outFile) {
	//RECT 1 100 200 17 30 BLUE RED

	outFile << "RECT\t" << ID << "\t" << Identifier << "\t";
	outFile << Corner1.x << "\t" << Corner1.y << "\t";
	outFile << Corner2.x << "\t" << Corner2.y << "\t";
	//GfxInfo FigGfxInfo;	//Figure graphis info
	outFile << FigGfxInfo.DrawClr << "\t";
	outFile << FigGfxInfo.FillClr << "\t";
	outFile << endl;
}

void CRectangle::Load(ifstream& Infile)
{
		//RECT 1 100 200 17 30 BLUE RED
	Infile >> ID >> Identifier;
	Infile >> Corner1.x >> Corner1.y;
	Infile >> Corner2.x >> Corner2.y;
	Infile >> FigGfxInfo.DrawClr;
	Infile >> FigGfxInfo.FillClr;
}

CFigure *CRectangle::clone() const
{
	return new CRectangle(*this);
}

void CRectangle::move(double& x, double& y, bool b)
{
	if(b)
		Movable = true;

	Point temp1 = Corner1, temp2 = Corner2;

	double centerx = (Corner1.x + Corner2.x) / 2.0;
	double centery = (Corner1.y + Corner2.y) / 2.0;
	double shiftx = x - centerx;
	double shifty = y - centery;
	Corner1.x = Corner1.x + shiftx;
	Corner2.x = Corner2.x + shiftx;
	Corner1.y = Corner1.y + shifty;
	Corner2.y = Corner2.y + shifty;

	if (!IsDrawn())
	{
		Movable = false;
		Corner1 = temp1, Corner2 = temp2;
		x = (Corner1.x + Corner2.x) / 2.0, y = (Corner1.y + Corner2.y) / 2.0;
		move(x, y, false);
	}


}

void CRectangle::Resize(int x, int y, bool& Valid, int c)
{
	if (c == 1)
	{
		Corner1.x = x;
		Corner1.y = y;
	}
	else
	{
		Corner2.x = x;
		Corner2.y = y;
	}
	Valid = IsDrawn();
}

int CRectangle::SelectCorner(int x, int y)
{
	if (y < (Corner1.y + Corner2.y) / 2)
		return 1;
	else
		return 2;
}
