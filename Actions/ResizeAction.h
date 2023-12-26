#ifndef RESIZEACTION_H
#define RESIZEACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"

class ResizeAction : public Action
{
	CFigure* Fig; // the selected figure
	Point P;
	bool Valid = true; // flag if the coordinates are not allowed
	int FigCorner; // the closest corner from the point

public:

	ResizeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	virtual Action* clone() const;
};

#endif