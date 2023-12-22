#ifndef UNDO_H
#define UNDO_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"
#include "Redo.h"

#define MAX 5

class Undo : public Action
{
	Action* UndoPtr; // pointer to last Undoable action
	//CFigure* FigurePtr;
	//Action* undoStack[MAX];
	//int undoIndex;
	//Action* redoStack [5];
	//int redoIndex;
	//Redo* redo;
 public:
	 Undo(ApplicationManager* pApp);


	 virtual void ReadActionParameters();


	 virtual void Execute();

	 virtual void undo();

	 virtual Action* clone() const override;
};
#endif