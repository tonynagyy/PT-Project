#include "CFigure.h"

//color CFigure::DrwClr = NULL;
//color CFigure::FlClr = NULL;

int CFigure::Count = 0;
//bool CFigure::WrngDrw = false;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.

	FigGfxInfo.DrawClr = UI.DrawColor;
	FigGfxInfo.FillClr = UI.FillColor;
	if (FigGfxInfo.FillClr == SNOW)
			FigGfxInfo.isFilled = false;
	else
			FigGfxInfo.isFilled = true;

	Selected = false;
	hidden = false;
	Movable = true;


}

CFigure::CFigure()
{
	SetSelected(false);
	Sethidden(false);
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::Sethidden(bool hd)
{
	hidden = hd;
}

bool CFigure::IfHidden()
{
	return hidden;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

int CFigure::GetID()
{
	return ID;
}

int CFigure::GetIdentifier()
{
	return Identifier;
}


color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

bool CFigure::IsMovable()
{
	return Movable;
}

void CFigure::SetMovable(bool b)
{
	Movable = b;
}

bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled;
}

void CFigure::ChngFillClr(color Fclr)
{
	if (Fclr == SNOW )
		FigGfxInfo.isFilled = false;
	else
		FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

float CFigure::Tri_Area(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
	// Calculate the area of the triangle using its corner points
	return abs((X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2)) / 2.0);
}


void CFigure::Save(ofstream& outFile) {
}
void CFigure::Load(ifstream& Infile) {
}
