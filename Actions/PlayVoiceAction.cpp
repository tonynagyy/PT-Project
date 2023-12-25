#include "PlayvoiceAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PlayVoiceAction::PlayVoiceAction(ApplicationManager* pApp): Action(pApp), _enablevoice(false)
{
}

void PlayVoiceAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	_enablevoice = pManager->Getplayvoicestatus();

	if (_enablevoice == true)
	{
		pOut->PrintMessage("Disable voice");
	}
	else
	{
		pOut->PrintMessage("Enable voice");
	}

}

void PlayVoiceAction::Execute()
{
	ReadActionParameters();

	if (_enablevoice == true) 
	{
		pManager->SetPlayvoicestatus(false);
	}
	else 
	{
		pManager->SetPlayvoicestatus(true);
	}
	
}

void PlayVoiceAction::undo()
{
}

Action* PlayVoiceAction::clone() const
{
	return new PlayVoiceAction(*this);
}
