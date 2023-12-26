#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class SwitchModeAction : public Action
{
	private:
		bool isDraw;
	public:
		SwitchModeAction(ApplicationManager *pApp, bool isDraw);
		void ReadActionParameters() override;
		void Execute() override;
		void undo() override;
		SwitchModeAction* clone() const override;
};

