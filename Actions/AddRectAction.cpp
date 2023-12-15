#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager *pApp) :Action(pApp) 
{
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;

	rect = NULL;
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	if (P1.x == 0 && P1.y == 0 && P2.x == 0 && P2.y == 0)
	{
		ReadActionParameters();
	}
	
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);
	rect = R;
	
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);

	//delete R;
}

void AddRectAction::undo()
{
	rect->Sethidden(true);
	//pManager->DeleteFig(rect);
}

Action* AddRectAction::clone() const
{
	return new AddRectAction(*this);
}

AddRectAction::~AddRectAction()
{
	delete rect;
	
}
