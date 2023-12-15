#ifndef ADD_Hexa_ACTION_H
#define ADD_Hexa_ACTION_H

#include "Action.h"
#include"../Figures/CFigure.h"
//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point center; //Hexagon center
	GfxInfo HexaGfxInfo;
	CFigure* hexa;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();
	virtual void undo();

	virtual Action* clone() const override;

	~AddHexaAction();
};

#endif