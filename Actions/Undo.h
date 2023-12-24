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
public:
	Undo(ApplicationManager* pApp);
	~Undo();

	void ReadActionParameters() override;
	void Execute() override;
	void undo() override;
	Action* clone() const override;
};
#endif