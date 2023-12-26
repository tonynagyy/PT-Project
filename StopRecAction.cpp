#include "StopRecAction.h"

/*
* StopRecAction::StopRecAction -> constructor
* @parameter: ApplicationManager* pApp
* @return: void
* Description: constructor to initialize the AppManager pointer and isInsideRecord to initally false
*/
StopRecAction::StopRecAction(ApplicationManager* pApp)
	:Action(pApp), isInsideRecord(false)
{
}

/*
* StopRecAction::ReadActionParameters
* @parameter: void
* @return: void
* Description: Reads the parameters required for the action to execute
* and sets the isInsideRecord to the current record status
*/
void StopRecAction::ReadActionParameters()
{
	isInsideRecord = pManager->GetRecordStatus();
}

/**
* StopRecAction::Execute
* @parameter: void
* @return: void
* Description: Stops the recording if the user is inside the recording mode
* and prints a message to the user
*/
void StopRecAction::Execute()
{
	ReadActionParameters();

	if (isInsideRecord)
	{
		pManager->SetInrecording(false);
		pManager->GetOutput()->PrintMessage("Recording stopped");
	}
	else
	{
		pManager->GetOutput()->PrintMessage("You are not in recording mode you cannot rec");
	}
	Sleep(2000);
	pManager->GetOutput()->ClearStatusBar();
}

void StopRecAction::undo()
{
}

StopRecAction* StopRecAction::clone() const
{
	return nullptr;
}
