#pragma once
#include "..\ApplicationManager.h"
#include "Action.h"

class ExitAction : public Action
{
	public:
		ExitAction(ApplicationManager* pApp);
		void ReadActionParameters() override;
		void Execute() override;
		void undo() override;
		ExitAction* clone() const override;
};
