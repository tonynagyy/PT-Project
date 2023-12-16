#ifndef SELECTCOLOUR_H
#define SELECTCOLOUR_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\DEFS.h"
#include "..\ApplicationManager.h"

class SelectColour : public Action
{
	CFigure* Fig;
	color Clr;

public:

	SelectColour(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif