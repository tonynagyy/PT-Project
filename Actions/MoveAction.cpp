#include "MoveAction.h"

MoveAction::MoveAction(ApplicationManager* pMan) :
	Action(pMan) , InicenterPoint(0,0), NewcenterPoint(0,0), Selectedfig(NULL)
{
}

MoveAction::MoveAction(const MoveAction& other)
	:Action(other), Selectedfig(NULL), InicenterPoint(other.InicenterPoint), NewcenterPoint(other.NewcenterPoint)
{
	if (other.Selectedfig != NULL)
		Selectedfig = other.Selectedfig->clone();
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
	if (Selectedfig == NULL)
	{
		ReadActionParameters();
	}

	if (Selectedfig != nullptr)
	{
		pManager->Movefigure(Selectedfig, NewcenterPoint.x, NewcenterPoint.y);
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
	if (Selectedfig != NULL)
	{
		delete Selectedfig;
		Selectedfig = NULL;
	}
}
