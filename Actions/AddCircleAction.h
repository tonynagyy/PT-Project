#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"
#include"../Figures/CFigure.h"
//Add circle Action class
class AddCircleAction : public Action
{
private:
	Point P1, P2; //circle points
	GfxInfo circleGfxInfo;
	CFigure* circle;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute();
	virtual void undo();

	virtual Action* clone() const override;

	 ~AddCircleAction();
};

#endif