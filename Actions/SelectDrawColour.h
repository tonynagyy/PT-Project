#ifndef SELECTDRAWCOLOUR_H
#define SELECTDRAWCOLOUR_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class SelectDrawColour : public Action
{
	color Clr;
	CFigure* Fig;
	color IniDrawClr;
public:

	SelectDrawColour(ApplicationManager* pApp);
	~SelectDrawColour();

	 void ReadActionParameters() override;	
	 void Execute() override;
	 void undo() override;
	 Action* clone()  const override;
};

#endif