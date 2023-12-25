#ifndef PLAYRECACTION_H
#define PLAYRECACTION_H

#include "Action.h"
#include "StartRecAction.h"
//#include "..\ApplicationManager.h"

class PlayRecAction : public Action
{
	int NumOfRecActions;
	Action* pAction;
	StartRecAction* RecordedActions;

public:
	PlayRecAction(ApplicationManager* pApp);

	~PlayRecAction();

	void ReadActionParameters() override;
	void Execute() override;
	void undo() override;
	PlayRecAction* clone() const override;
};

#endif
