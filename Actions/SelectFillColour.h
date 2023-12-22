#ifndef SELECTFILLCOLOUR_H
#define SELECTFILLCOLOUR_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class SelectFillColour : public Action
{
	color Clr;
	CFigure* Fig;
	color IniFillColour;
public:

	SelectFillColour(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void undo();

	virtual Action* clone()  const override;

	~SelectFillColour();
};

#endif