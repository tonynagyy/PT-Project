#include "MoveAction.h"

MoveAction::MoveAction(ApplicationManager* pMan) :Action(pMan) 
{
	Selectedfig = NULL;
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Selectedfig = pManager->GetSelectedFigure();

	pOut->PrintMessage(" select the place you want to move the figure to");
	pIn->GetPointClicked(Selectedpoint.x, Selectedpoint.y);
	
	pOut->ClearStatusBar();
}

void MoveAction::Execute()
{ 
	if (Selectedfig == NULL)
	{
		ReadActionParameters();
	}
	if (Selectedfig != nullptr)
	{
		Selectedfig->move(Selectedpoint.x, Selectedpoint.y);
	}
}

void MoveAction::undo()
{
}

Action* MoveAction::clone() const
{
	return nullptr;
}
