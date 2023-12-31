#ifndef PICKCLRACTION_H
#define PICKCLRACTION_H

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

class PickClrAction : public Action
{
	int CountWrg = 0; // Counter for wrong answers
	int CountCrt = 0; // Counter for correct answers
	Point P;
	CFigure* Fig;
	CFigure* CheckFig;
	bool Exit = false; // check if the user want to exit from the game

public:
	PickClrAction(ApplicationManager* pApp);
	void ReadActionParameters() override;
	void Execute() override;
	void undo() override;
	bool CheckAns(); // checking if the points clicked are correct or not 

	PickClrAction* clone() const override;
};


#endif
