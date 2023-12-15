#include "AddSquareAction.h"
#include "../Figures/CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp) 
{
	center.x = 0;
	center.y = 0;

	square = NULL;
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center of Square");

	//Read the center and store in point center
	pIn->GetPointClicked(center.x, center.y);


	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	if (center.x == 0 && center.y == 0)
	{
		ReadActionParameters();
	}
	

	//Create a Square with the parameters read from the user
	CSquare * S = new CSquare (center, SquareGfxInfo);
	square = S->clone();
	//Add the Square to the list of figures
	pManager->AddFigure(square);

	delete S;
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
}
