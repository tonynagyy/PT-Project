#include "Redo.h"

Redo::Redo(ApplicationManager* pApp) :Action(pApp)
{
	Redoptr = NULL;
}

void Redo::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	Redoptr = pManager->GetLastRedo();  //Get the last undoable action

	if (Redoptr != NULL)
	{
		Redoptr = Redoptr->clone();
	}

	if (Redoptr != NULL){
		pOut->PrintMessage("Redo the Last Action");
	}
	else{
		pOut->PrintMessage("No Action to Redo");
	}
}

void Redo::Execute()
{
	if (Redoptr == NULL)
	{
		ReadActionParameters(); // set the redo action parameters
	}

	if (Redoptr != NULL)
	{
		Redoptr->Execute(); //  Calling the Execute function of the action to be redone
	}

	if (!(pManager->GetPlayrecStatus()))
	{
		pManager->SetInUndoList(Redoptr); // set the redo action in the undo list to be undone later if wanted
	}
}

void Redo::undo()  // No implementation needed
{
}

Action* Redo::clone() const
{
    return new Redo(*this);
}

Redo::~Redo()
{
	//delete Redoptr;
	Redoptr = NULL;
}
