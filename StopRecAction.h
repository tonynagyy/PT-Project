#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

/*
* class StopRecAction inhterits from Action class interface
* it is responsible for stopping the recording of the actions
* @param isInsideRecord: boolean to check if the user is inside the recording mode or not
*/
class StopRecAction : public Action
{
	bool isInsideRecord;
	public:
		StopRecAction(ApplicationManager* pApp);
		void Execute() override;
		void ReadActionParameters() override;
		void undo() override;
		StopRecAction *clone() const override;
};

