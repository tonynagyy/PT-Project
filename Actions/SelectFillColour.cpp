#include "SelectFillColour.h"

SelectFillColour::SelectFillColour(ApplicationManager* pApp) : 
	Action(pApp) ,Fig(NULL)
{
	Fig = NULL;
}

SelectFillColour::SelectFillColour(const SelectFillColour& SelFillClr)
	:Action(SelFillClr), Fig(NULL), Clr(SelFillClr.Clr), IniFillColour(SelFillClr.IniFillColour)
{
	if (SelFillClr.Fig != NULL) 
	{
		Fig = SelFillClr.Fig->clone();
	}
}

void SelectFillColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	Fig = pManager->GetSelectedFigure();

	if (Fig != NULL) 
	{
		Fig = pManager->GetSelectedFigure()->clone();
		IniFillColour = Fig->GetFillClr();
		pManager->Setundoable(true);
	}

	if (Fig)
	{
		pOut->PrintMessage("Select the filling colour");
		Clr = pOut->GetColour(pIn, pOut, ITM_FILLINGCLR);
		if (Clr == SNOW)
			Clr = UI.FillColor;
		pOut->ClearStatusBar();
		pManager->UpdateInterface();
	}
	else
	{
		pOut->PrintMessage("Select a figure first to choose the filling colour");
		Clr = UI.FillColor;
	}
}

void SelectFillColour::Execute()
{
	Output* pOut = pManager->GetOutput();

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

	pOut->setCrntFillColor(Clr);
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
	if (Fig != NULL)
	{
		delete Fig;
		Fig = NULL;
	}
}
