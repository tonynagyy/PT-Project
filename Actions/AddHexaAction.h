#ifndef ADD_Hexa_ACTION_H
#define ADD_Hexa_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point center; //Hexagon center
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();

};

#endif