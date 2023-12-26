#include "clearall.h"
#include "string"

clearAll::clearAll(ApplicationManager* pMan)
	:Action(pMan) 
{
}

void clearAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->setCrntDrawColor(BLUE);
	pOut->setCrntFillColor(SNOW);

	pOut->PrintMessage("Clearing all Actions");
}

void clearAll::Execute()
{
	ReadActionParameters();
	pManager->setActionsCount(-1);/*Need for Rec to Start at the beginne only or just after clear*/
	pManager->Clearall();

}

void clearAll::undo() 
{
}

Action* clearAll::clone() const 
{
	return new clearAll(*this);
}


