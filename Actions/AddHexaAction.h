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
	bool PlayHexaVoice;
public:
	AddHexaAction(ApplicationManager* pApp, bool voiceh);
	AddHexaAction(const AddHexaAction & other);
	~AddHexaAction();

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual Action* clone() const override;
};

#endif