#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
//#include "..\Figures\CRectangle.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CRectangle* rect;
	bool PlayRectVoice;
public:
	AddRectAction(ApplicationManager *pApp, bool voice);
	AddRectAction(const AddRectAction& other);
	~AddRectAction();

	virtual void ReadActionParameters();
	virtual void Execute() ;
	virtual void undo();
	Action* clone() const override;
};

#endif