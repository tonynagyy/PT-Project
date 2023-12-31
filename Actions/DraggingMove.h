#ifndef DRAGGINGMOVE_H
#define DRAGGINGMOVE_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"

class DraggingMove : public Action
{
	CFigure* Fig; // the selected figure
	Point P;

public:

	DraggingMove(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual Action* clone() const;
};


#endif