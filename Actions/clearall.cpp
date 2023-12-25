#include "clearall.h"
#include "string"
using std::string;

clearAll::clearAll(ApplicationManager* pMan)
	:Action(pMan) 
{
}

void clearAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Are you sure you want to CLEAR ALL Y or N ");
	warningMsg = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void clearAll::Execute()
{
	ReadActionParameters();

	if (warningMsg == "Y" || warningMsg == "y" || warningMsg == "YES" || warningMsg == "yes")
	{
		pManager->Clearall();
	}
}

void clearAll::undo() 
{
}

Action* clearAll::clone() const 
{
	return nullptr;
}


