#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
	circle = NULL;
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;

}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New circle: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New circle: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	circleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	circleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	circleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	if (P1.x == 0 && P1.y == 0 && P2.x == 0 && P2.y == 0)
	{
		ReadActionParameters();
	}
	

	//Create a circle with the parameters read from the user
	CCircle* circ = new CCircle(P1, P2, circleGfxInfo);
	circle = circ->clone();
	//Add the circle to the list of figures
	pManager->AddFigure(circle);
	
	delete circ;
}

void AddCircleAction::undo()
{
	pManager->DeleteFig(circle);
}

Action* AddCircleAction::clone() const
{
	return new AddCircleAction(*this);
}

AddCircleAction::~AddCircleAction()
{
	delete circle;
}
