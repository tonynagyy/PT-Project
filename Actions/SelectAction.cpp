#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Action: Select a figure");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	Fig = pManager->GetFigure(P.x, P.y);

	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Fig != nullptr)
		if (Fig->IsSelected())
		{
			Fig->SetSelected(false);
		}
		else
		{
			pManager->UnSelect();
			Fig->SetSelected(true);
			Fig->PrintInfo(pOut);
		}
}

void SelectAction::undo()
{
}

Action* SelectAction::clone() const
{
	return new SelectAction(*this);
}
