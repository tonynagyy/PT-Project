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
	{
		Fig->SetSelected(true);
		Fig->PrintInfo(pOut);
	}
	
}

CFigure* SelectAction::Get_Fig()
{
	return Fig;
}

void SelectAction::Unselect()
{
	if (Fig != nullptr)
		Fig->SetSelected(false);
}
