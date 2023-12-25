#include "AddCircleAction.h"

#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :
	Action(pApp), circle(NULL), P1(0,0), P2(0,0)
{
}

void AddCircleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New circle: Click at first point");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New circle: Click at second point");
	pIn->GetPointClicked(P2.x, P2.y);

	/*Intializing the dataMembers of the GFXInfo*/
	circleGfxInfo.isFilled = false;	//default is not filled
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
	
	if (circle == NULL)
	{
		//Create a circle with the parameters read from the user
		circle = new CCircle(P1, P2, circleGfxInfo);
	}

	pManager->AddFigure(circle);
}

void AddCircleAction::undo()
{
	pManager->DeleteFig(circle);
}

AddCircleAction* AddCircleAction::clone() const
{
	return new AddCircleAction(*this);
}

AddCircleAction::~AddCircleAction()
{
	delete circle;
	circle = NULL;
}
