#include "CSquare.h"

//int CSquare::Count = 0;

CSquare::CSquare(const Point& p1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), center(p1)
{

	Identifier = 2;
	if (CalcArea() && IsDrawn()) 
	{
		Count++;
		ID = Count;
	}
}


void CSquare::Draw(Output* pOut) const
{
	if (isDrawn)
		//Call Output::DrawSquare to draw a square on the screen	
		pOut->DrawSquare(center, FigGfxInfo, Selected, Modified_Length);
}

bool CSquare::InFigure(int x, int y)
{
    //Check if the point in the region of the square or not
	if(!Modified_Length)
		return (DELTA(center.x, x) < HALF_SQUARE_LENGTH && DELTA(center.y , y) < HALF_SQUARE_LENGTH);
	else
		return (DELTA(center.x, x) < Modified_Length && DELTA(center.y, y) < Modified_Length);
}

double CSquare::CalcArea()
{
    // Calculate the area of the square
    return 4 * HALF_SQUARE_LENGTH * HALF_SQUARE_LENGTH;
}

void CSquare::PrintInfo(Output* pOut)
{
	string msg;

	string S = "Square ID: ";
	string S1 = "  Figure: Square    Area: ";
	string S2 = "  Center: (";
	string S3 = " , ";
	string S4 = ")   Is Filled :  ";
	string S5 = " False";
	string S6 = " True";
	if (FigGfxInfo.isFilled)
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string(center.x) + S3 + to_string(center.y) + S4 + S6;
		pOut->PrintMessage(msg);
	}
	else
	{
		string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string(center.x) + S3 + to_string(center.y) + S4 + S5;
		pOut->PrintMessage(msg);
	}
}
bool CSquare::IsDrawn()
{
	isDrawn = !(center.y - HALF_SQUARE_LENGTH < UI.ToolBarHeight || center.y + HALF_SQUARE_LENGTH > UI.height - UI.StatusBarHeight);
	bool b = !(center.y - Modified_Length < UI.ToolBarHeight || center.y + Modified_Length > UI.height - UI.StatusBarHeight);
	return (isDrawn && b);
}

int CSquare::GetID()
{
	return ID;
}

Point CSquare::Getcenter()
{
	return center;
}
color CSquare::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CSquare::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CSquare::Save(ofstream& outFile) {
	outFile << "SQ\t" << ID << "\t" << Identifier << "\t" << center.x << "\t" << center.y << "\t";
	outFile << FigGfxInfo.DrawClr << "\t";
	outFile << FigGfxInfo.FillClr << endl;
}

void CSquare::move(double& x, double& y, bool b)
{
	if(b)
		Movable = true;
	Point temp = center;

	center.x = x;
	center.y = y;

	if (!IsDrawn())
	{
		Movable = false;
		center = temp;
		x = center.x, y = center.y;
		move(x, y, false);
	}
}

void CSquare::Resize(int x, int y, bool& Valid, int c)
{
	int temp = Modified_Length;

	Modified_Length = DEST(x, y, center.x, center.y);
	if (!(Valid = IsDrawn()))
		Modified_Length = temp;
}

void CSquare::Load(ifstream& Infile) {
	Infile >> ID >> Identifier >> center.x >> center.y;
	Infile >> FigGfxInfo.DrawClr;
	Infile >> FigGfxInfo.FillClr;
}

CFigure* CSquare::clone() const
{
	return new CSquare(*this);
}
