#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"
#include"../Figures/CFigure.h"
//Add Triangle Action class
class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo triangleGfxInfo;
	CFigure* triangle;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();

	virtual Action* clone() const override;

	 ~AddTriangleAction();
};

#endif
 

