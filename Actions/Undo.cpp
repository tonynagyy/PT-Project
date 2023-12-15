#include "Undo.h"

Undo::Undo(ApplicationManager* pApp):Action(pApp)
{
	UndoPtr = NULL;
	FigurePtr = NULL;
	//UndoPtr = new Action(pApp);
}

void Undo::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	UndoPtr = pManager->GetLastUndo();
	


	if (UndoPtr != NULL)
	{
		pOut->PrintMessage("Undo the Last Action");
	}
	else
	{
		pOut->PrintMessage("No Action to Undo");
	}



}
	

void Undo::Execute()
{
	ReadActionParameters();

	if (UndoPtr != NULL)
	{
		UndoPtr->undo();
	}

	pManager->SetInRedoList(UndoPtr);
	/*
	if (undoIndex >= 0) {
		// Move the last action from the undo stack to the redo stack
		redoStack[++redoIndex] = undoStack[undoIndex--];
		redoStack[redoIndex]->undo();
	}
	*/
	
}

void Undo::undo()
{
}

Action* Undo::clone() const
{
	return new Undo(*this);
}
