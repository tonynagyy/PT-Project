#include "SelectFillColour.h"

SelectFillColour::SelectFillColour(ApplicationManager* pApp) : Action(pApp)
{
	Fig = NULL;
}

void SelectFillColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	Fig = pManager->GetSelectedFigure()->clone();

	if (Fig != NULL)
	{
		IniFillColour = Fig->GetFillClr();
	}

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
	if (Fig == NULL)
	{
		ReadActionParameters();
	}

	if (Fig)
	{
		//if (Clr != NULL )
		pManager->Changefillcolor(Fig, Clr);
			//Fig->ChngFillClr(Clr);
		
	}
}

void SelectFillColour::undo()
{
	if (Fig != NULL)
	{
		pManager->Changefillcolor(Fig, IniFillColour);
	}

}

Action* SelectFillColour::clone()  const
{
	return new SelectFillColour(*this);
}

SelectFillColour::~SelectFillColour()
{
	delete Fig;
	Fig = NULL;
}
