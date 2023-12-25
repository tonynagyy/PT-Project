#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"
#include"../Figures/CFigure.h"

class AddCircleAction : public Action
{
private:
	Point P1, P2; //circle points
	GfxInfo circleGfxInfo;
	CFigure* circle;
public:
	AddCircleAction(ApplicationManager* pApp);
	 ~AddCircleAction();

	void ReadActionParameters() override;
	 void Execute() override;
	 void undo() override;
	AddCircleAction* clone() const override;
};
#endif