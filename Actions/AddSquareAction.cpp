#include "AddSquareAction.h"
#include "../Figures/CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :
	Action(pApp) , square(NULL), center(0,0)
{
}

void AddSquareAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center of Square");
	pIn->GetPointClicked(center.x, center.y);

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.isFilled = false;	//default is not filled
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	if (center.x == 0 && center.y == 0)
	{
		ReadActionParameters();
	}
	
	if (square == NULL)
	{
		square = new CSquare(center, SquareGfxInfo);
	}

	pManager->AddFigure(square);
}

void AddSquareAction::undo()
{
	pManager->DeleteFig(square);
}

Action* AddSquareAction::clone() const
{
	return new AddSquareAction(*this);
}

AddSquareAction::~AddSquareAction()
{
	delete square;
	square = NULL;
}
