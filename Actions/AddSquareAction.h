#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddSquareAction : public Action
{
private:
	Point center; //Hexagon center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();

};

#endif