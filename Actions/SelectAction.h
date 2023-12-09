#ifndef SELECTACTION_H
#define SELECTACTION_H




#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"
#include "..\Figures\CFigure.h"

class SelectAction : public Action
{
private:

	Point P;
	CFigure* Fig;

public:
	SelectAction(ApplicationManager* pApp);

	// get point and the figure from the user
	virtual void ReadActionParameters();
	virtual void Execute();
	CFigure* Get_Fig();
};


#endif