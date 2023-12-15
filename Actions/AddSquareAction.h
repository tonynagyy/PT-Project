#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Action.h"
#include"../Figures/CFigure.h"

//Add Square Action class
class AddSquareAction : public Action
{
private:
	Point center; //Square center
	GfxInfo SquareGfxInfo;
	CFigure* square;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
	virtual void undo();

	virtual Action* clone() const override;

	~AddSquareAction();
};

#endif