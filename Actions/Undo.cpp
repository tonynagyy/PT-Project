#include "Undo.h"

Undo::Undo(ApplicationManager* pApp):Action(pApp)
{
	UndoPtr = NULL;
	//FigurePtr = NULL;
	//UndoPtr = new Action(pApp);
}

void Undo::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	UndoPtr = (pManager->GetLastUndo());//Get the last undoable action 
	
	if (UndoPtr != NULL)
		UndoPtr = (pManager->GetLastUndo())->clone();


	if (UndoPtr != NULL){
		pOut->PrintMessage("Undo the Last Action");
	}
	else{
		pOut->PrintMessage("No Action to Undo");
	}



}
	

void Undo::Execute()
{
	if (UndoPtr == NULL)
	{
		ReadActionParameters(); // set the undo action parameters
	}

	if (UndoPtr != NULL)
	{
		UndoPtr->undo();  // Calling the undo function of the action to be undone
	}
	if ( !(pManager->GetPlayrecStatus()) )
	{
		pManager->SetInRedoList(UndoPtr);  // set the undoable action in redo list to be redone later if wanted
	}
}

void Undo::undo() // No implementation needed
{
}

Action* Undo::clone() const
{
	return new Undo(*this);
}

Undo::~Undo()
{
	delete UndoPtr;
	UndoPtr = NULL;
}
