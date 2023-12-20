#include "CFigure.h"

color CFigure::DrwClr = NULL;
color CFigure::FlClr = NULL;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{

	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	if (DrwClr != NULL)
		FigGfxInfo.DrawClr = DrwClr;
	if (FlClr != NULL)
	{
		FigGfxInfo.FillClr = FlClr;
		FigGfxInfo.isFilled = true;
	}
	Selected = false;
	hidden = false;
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


void CFigure::FakeDraw(Output* pOut)
{
	Draw(pOut);
}

void CFigure::ChngDrawClr(color Dclr)
{
	DrwClr = Dclr;
	FigGfxInfo.DrawClr = Dclr;
}

int CFigure::GetID()
{
	return ID;
}

color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}

color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FlClr = Fclr;
	FigGfxInfo.FillClr = Fclr;
}

float CFigure::Tri_Area(int X1, int Y1, int X2, int Y2, int X3, int Y3)
{
	// Calculate the area of the triangle using its corner points
	return abs((X1 * (Y2 - Y3) + X2 * (Y3 - Y1) + X3 * (Y1 - Y2)) / 2.0);
}

void CFigure::Save(ofstream& outFile) {

}
