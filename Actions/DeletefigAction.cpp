#include "DeletefigAction.h"

DeletefigAction::DeletefigAction(ApplicationManager* pApp): 
	Action(pApp), selectedfig(NULL)
{
}
DeletefigAction::DeletefigAction(const DeletefigAction& other) :
	Action(other), selectedfig(NULL)
{
	if (other.selectedfig != NULL)
	{
		selectedfig = other.selectedfig->clone();
	}
}

void DeletefigAction::ReadActionParameters()
{

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
		pManager->Setundoable(true);
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
	if (selectedfig)
	{
		selectedfig->SetSelected(false);
		pManager->AddFigure(selectedfig);
	}
}

DeletefigAction* DeletefigAction::clone() const
{
	return new DeletefigAction(*this);
}

DeletefigAction::~DeletefigAction()
{
	if (selectedfig != NULL)
	{
		delete selectedfig;
		selectedfig = NULL; 
	}
}
