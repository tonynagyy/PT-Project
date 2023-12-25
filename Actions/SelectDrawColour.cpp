#include "SelectDrawColour.h"

SelectDrawColour::SelectDrawColour(ApplicationManager* pApp) : Action(pApp), Fig(NULL)
{
}

SelectDrawColour::SelectDrawColour(const SelectDrawColour& other) :
	Action(other), Fig(NULL), IniDrawClr(other.IniDrawClr), Clr(other.Clr)
{
	if (other.Fig)
	{
		Fig = other.Fig->clone();
	}
}

void SelectDrawColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	Fig = pManager->GetSelectedFigure();
	if (Fig != NULL) {
		Fig = pManager->GetSelectedFigure()->clone();
		IniDrawClr = Fig->GetDrawClr();
		pManager->Setundoable(true);
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
	Output* pOut = pManager->GetOutput();

	if (Fig == NULL)
	{
		ReadActionParameters();
	}

	if (Fig)
	{
		pManager->Changedrawcolor(Fig, Clr);
	}

	pOut->setCrntDrawColor(Clr);
}

void SelectDrawColour::undo()
{
	if (Fig != NULL)
	{
		pManager->Changedrawcolor(Fig, IniDrawClr);
	}
}

Action* SelectDrawColour::clone()  const
{
	return new SelectDrawColour(*this);
}

SelectDrawColour::~SelectDrawColour()
{
	if (Fig != NULL)
	{
		delete Fig;
		Fig = NULL;
	}
}
