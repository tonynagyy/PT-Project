#include "SelectColour.h"

SelectColour::SelectColour(ApplicationManager* pApp) : Action(pApp)
{
}

void SelectColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a colour");
	Clr = pOut->GetColour(pIn, pOut);

	pManager->UpdateInterface();

	int x, y;

	pIn->GetPointClicked(x, y);
	Fig = pManager->GetFigure(x, y);

	pOut->ClearStatusBar();


}

void SelectColour::Execute()
{
	ReadActionParameters();

	if(Fig)
		Fig->ChngDrawClr(Clr);
}
