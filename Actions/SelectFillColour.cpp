#include "SelectFillColour.h"

SelectFillColour::SelectFillColour(ApplicationManager* pApp) : Action(pApp)
{
}

void SelectFillColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	Fig = pManager->GetSelectedFigure();
	if (Fig)
	{
		pOut->PrintMessage("Select the filling colour");
		Clr = pOut->GetColour(pIn, pOut, ITM_FILLINGCLR);
		pOut->ClearStatusBar();
		pManager->UpdateInterface();
	}
	else
		pOut->PrintMessage("Select a figure first to choose the filling colour");
}

void SelectFillColour::Execute()
{
	ReadActionParameters();

	if (Fig)
	{
		if (Clr != NULL)
			Fig->ChngFillClr(Clr);
	}
}

void SelectFillColour::undo()
{
}

Action* SelectFillColour::clone()  const
{
	return nullptr;
}
