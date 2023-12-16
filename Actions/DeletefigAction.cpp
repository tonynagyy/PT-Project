#include "DeletefigAction.h"

DeletefigAction::DeletefigAction(ApplicationManager* pApp): Action(pApp)
{
	selectedfig = NULL;
}

void DeletefigAction::ReadActionParameters()
{

    //Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//selectedfig->clone();
	selectedfig = pManager->GetSelectedFigure();

}

void DeletefigAction::Execute()
{
	if (selectedfig == NULL)
	{
		ReadActionParameters();
	}
	
	if (selectedfig != nullptr)
	{
		pManager->DeleteFig(selectedfig);
	}
}

void DeletefigAction::undo()
{
	selectedfig->SetSelected(false);
	selectedfig->Sethidden(false);
	//pManager->UpdateInterface();
	//pManager->AddFigure(selectedfig);
}

Action* DeletefigAction::clone() const
{
	return new DeletefigAction(*this);
}
