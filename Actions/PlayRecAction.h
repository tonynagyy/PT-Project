#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "StartRecAction.h"
#include <iostream>

class PlayRecAction : public Action
{
	StartRecAction* RecordedActions;
	int NumOfRecActions;
	Action* pAction;
public:
	PlayRecAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();

	virtual PlayRecAction* clone() const override;


	~PlayRecAction();


};

