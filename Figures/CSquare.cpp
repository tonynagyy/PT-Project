#include "CSquare.h"

//int CSquare::Count = 0;

CSquare::CSquare(const Point&p1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), center(p1) 
{
	
	Identifier = 2;
	Count++;
	ID = Count;
}

CSquare::CSquare()
{
	SetSelected(false);
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
/*
int CSquare::Counter()
{
	return Count;
}
*/

void CSquare::FakeDraw(Output* pOut)
{
	FigGfxInfo.DrawClr = LIGHTGOLDENRODYELLOW;
	Draw(pOut);
	FigGfxInfo.DrawClr = BLUE;
}

int CSquare::GetID()
{
	return ID;
}

/*
int CSquare::GetNum()
{
	return Num;
}

void CSquare::IncNum()
{
	Num++;
}

void CSquare::DecNum()
{
	Num--;
}
*/
color CSquare::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CSquare::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CSquare::Save(ofstream& outFile) {
	outFile << "SQ\t" << ID << "\t" << center.x << "\t" << center.y << "\t";
	outFile << FigGfxInfo.DrawClr << "\t";
	outFile << FigGfxInfo.FillClr << endl;
}

void CSquare::move(double x, double y)
{
	center.x = x;
	center.y = y;
}

void CSquare::Load(ifstream& Infile) {
	Infile >> ID >> center.x >> center.y;
	Infile >> FigGfxInfo.DrawClr;
	Infile >> FigGfxInfo.FillClr;
}

CFigure* CSquare::clone() const
{
	return new CSquare(*this);
}
