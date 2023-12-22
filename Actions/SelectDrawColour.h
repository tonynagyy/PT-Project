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

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void undo();

	virtual Action* clone()  const override;

	~SelectDrawColour();
};

#endif