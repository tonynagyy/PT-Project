#include "PlayRecAction.h"
#include "StartRecAction.h"
//#include<windows.h>

PlayRecAction::PlayRecAction(ApplicationManager* pApp) : 
	Action(pApp), NumOfRecActions(0), pAction(NULL)
{
	RecordedActions = dynamic_cast<StartRecAction*> (pManager->GetStartrecaction());

	if (RecordedActions != NULL)
	{
		if (RecordedActions->getFront() == NULL)
		{
			delete RecordedActions;
			RecordedActions = NULL;
			pManager->GetStartrecaction() = NULL;
		}
	}

}

void PlayRecAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if (RecordedActions == NULL)
	{
		pOut->PrintMessage("No recorded actions to be played");
	}
	else
	{
		NumOfRecActions = RecordedActions->getQueueSize();
		if (NumOfRecActions == 0)
		{
			pOut->PrintMessage("No recorded actions to be played");
		}
		else
		{
			pManager->SetPlayrec(true);
			pManager->Clearall();
			pManager->UpdateInterface();
			pOut->PrintMessage("Displaying the recording actions");
			Sleep(2000);
			pOut->ClearStatusBar();
		}
	}

}

void PlayRecAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	if (RecordedActions != NULL && NumOfRecActions != 0)
	{
		for (int i = 0; i < NumOfRecActions; i++)
		{
			pAction = RecordedActions->dequeue();
			pAction->Execute();
			pManager->UpdateInterface();
			Sleep(2000);

			//delete pAction;
			//pAction = NULL;
		}
		RecordedActions->setFrontIndex(0);
		RecordedActions->setRearIndex(NumOfRecActions - 1);
		pOut->PrintMessage("The Play Recording Finished");
	}
	pManager->SetPlayrec(false);
}


void PlayRecAction::undo()
{
}

PlayRecAction* PlayRecAction::clone() const
{
	return new PlayRecAction(*this);
}

PlayRecAction::~PlayRecAction()
{
	//delete RecordedActions;
	//RecordedActions = NULL;
}
