#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"
#include"../Figures/CFigure.h"

class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo triangleGfxInfo;
	CFigure* triangle;
	bool PlayTrigSound;
public:
	AddTriangleAction(ApplicationManager* pApp, bool voice);
	AddTriangleAction(const AddTriangleAction& other);
	 ~AddTriangleAction();

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
	virtual Action* clone() const override;
};

#endif
 

