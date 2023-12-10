#ifndef PICKFIGACTION_H
#define PICKFIGACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\DEFS.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"

class PickFigAction : public Action
{
	int CountWrg = 0; // Counter for wrong answers
	int CountCrt = 0; // Counter for correct answers
	Point P;
	CFigure* Fig;
	CFigure* CheckFig;

public:
	PickFigAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	bool CheckAns();

};


#endif
