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
	if (selectedfig == NULL)
	{
		pOut->PrintMessage("Select the figure you want to delete first");
	}
	else
	{
		selectedfig = pManager->GetSelectedFigure()->clone();
		pOut->PrintMessage("delete the selected figure");
	}
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

void DeletefigAction::undo()  // undoing the delete operation by adding the figure deleted
{
	selectedfig->SetSelected(false);
	pManager->AddFigure(selectedfig);
}

Action* DeletefigAction::clone() const
{
	return new DeletefigAction(*this);
}

DeletefigAction::~DeletefigAction()
{
	delete selectedfig;
	selectedfig = NULL;	
}
