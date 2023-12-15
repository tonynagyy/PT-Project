#include "Redo.h"

Redo::Redo(ApplicationManager* pApp) :Action(pApp)
{
}

void Redo::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	Redoptr = pManager->GetLastRedo();

	//pManager->SetInUndoList(Redoptr);

	if (Redoptr != NULL)
	{
		pOut->PrintMessage("Redo the Last Action");
	}
	else
	{
		pOut->PrintMessage("No Action to Redo");
	}




}

void Redo::Execute()
{
	ReadActionParameters();

	if (Redoptr != NULL)
	{
		Redoptr->Execute();
	}

	pManager->SetInUndoList(Redoptr);

	//delete Redoptr;
	//Redoptr = NULL;
}

void Redo::undo()
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
