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
	~AddHexaAction();

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual Action* clone() const override;
};

#endif