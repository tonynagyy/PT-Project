#include "SelectDrawColour.h"

SelectDrawColour::SelectDrawColour(ApplicationManager* pApp) : Action(pApp)
{
	Fig = NULL;
}

void SelectDrawColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	Fig = pManager->GetSelectedFigure();

	if (Fig != NULL)
	{
		IniDrawClr = Fig->GetDrawClr();
	}
		
	

	if (Fig)
	{
		pOut->PrintMessage("Select the drawing colour");
		Clr = pOut->GetColour(pIn, pOut, ITM_DRAWINGCLR);
		pOut->ClearStatusBar();
		pManager->UpdateInterface();
	}
	else
		pOut->PrintMessage("Select a figure first to choose the drawing colour");
}

void SelectDrawColour::Execute()
{
	if (Fig == NULL)
	{
		ReadActionParameters();
	}

	if (Fig)
	{
		//if (Clr != NULL)
			Fig->ChngDrawClr(Clr);
	}
}

void SelectDrawColour::undo()
{
	if (Fig != NULL)
	{
		Fig->ChngDrawClr(IniDrawClr);
	}
}

Action* SelectDrawColour::clone()  const
{
	return new SelectDrawColour(*this);
}