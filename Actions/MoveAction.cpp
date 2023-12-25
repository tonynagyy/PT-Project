#include "MoveAction.h"

MoveAction::MoveAction(ApplicationManager* pMan) :
	Action(pMan) , Selectedfig(NULL)
{
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	Selectedfig = pManager->GetSelectedFigure();

	if (Selectedfig != NULL)
	{
		Selectedfig = pManager->GetSelectedFigure()->clone();
		InicenterPoint = Selectedfig->Getcenter();

		pOut->PrintMessage("click new point to move the figure to it");
		pIn->GetPointClicked(NewcenterPoint.x, NewcenterPoint.y);
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("Select a figure first to be moved");
	    
}

void MoveAction::Execute()
{ 
	Output* pOut = pManager->GetOutput();

	if (Selectedfig == NULL)
	{
		ReadActionParameters();
	}

	if (Selectedfig != nullptr)
	{
		Selectedfig->SetMovable(true);
		pManager->Movefigure(Selectedfig, NewcenterPoint.x, NewcenterPoint.y);
		if (!Selectedfig->IsMovable())
			pOut->PrintMessage("Invalid Action");
	}
}

void MoveAction::undo()
{
	if (Selectedfig != NULL)
	{
		pManager->Movefigure(Selectedfig, InicenterPoint.x, InicenterPoint.y);
	}
}

Action* MoveAction::clone() const
{
	return new MoveAction(*this);
}

MoveAction::~MoveAction()
{
	delete Selectedfig;
	Selectedfig = NULL;
}
