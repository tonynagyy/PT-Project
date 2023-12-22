#ifndef PICKCLRFigACTION_H
#define PICKCLRFigACTION_H

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

class PickClrFigAction : public Action
{
	int CountWrg = 0; // Counter for wrong answers
	int CountCrt = 0; // Counter for correct answers
	Point P;
	CFigure* Fig;
	CFigure* CheckFig;

public:
	PickClrFigAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	bool CheckAns();
	string ColourToString(CFigure* F);  // convert the colour to string

	virtual void undo();


	virtual Action* clone() const override;
};


#endif
