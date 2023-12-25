#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* rect;
	bool PlayRectVoice;
public:
	AddRectAction(ApplicationManager *pApp, bool voice);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	virtual void undo();

	Action* clone() const override;

	~AddRectAction();
};

#endif