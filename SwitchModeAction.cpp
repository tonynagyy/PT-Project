#include "SwitchModeAction.h"

SwitchModeAction::SwitchModeAction(ApplicationManager* pApp, bool isDraw)
	:Action(pApp), isDraw(isDraw)
{
}

void SwitchModeAction::ReadActionParameters()
{
}

void SwitchModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (isDraw)
	{
		pOut->CreateDrawToolBar();
	}
	else
	{
		pOut->CreatePlayToolBar();
	}
	pOut->ClearStatusBar();
}

void SwitchModeAction::undo()
{
}

SwitchModeAction* SwitchModeAction::clone() const
{
	return new SwitchModeAction(*this);
}
