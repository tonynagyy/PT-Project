#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"

//Add circle Action class
class AddCircleAction : public Action
{
private:
	Point P1, P2; //circle points
	GfxInfo circleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();


};

#endif