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
	SelectFillColour(const SelectFillColour& SelFillClr);
	~SelectFillColour();

	void ReadActionParameters() override;
	void Execute() override;
	void undo() override;
	Action* clone()  const override;
};

#endif