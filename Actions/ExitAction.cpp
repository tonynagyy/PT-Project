#include "ExitActionh.h"

ExitAction::ExitAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	pOut->PrintMessage("You are about to exit the application");
	Sleep(1000);
}

void ExitAction::Execute()
{
	pManager->Clearall();
}

void ExitAction::undo()
{
}

ExitAction* ExitAction::clone() const
{
	return new ExitAction(*this);
}
