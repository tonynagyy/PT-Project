#ifndef SELECTACTION_H
#define SELECTACTION_H

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
	CFigure* Fig = nullptr;
public:
	SelectAction(ApplicationManager* pApp);
	SelectAction(const SelectAction& other);

	// get point and the figure from the user
	 void ReadActionParameters() override;
	 void Execute() override;
	 void undo() override;
	 Action* clone() const override;
};


#endif