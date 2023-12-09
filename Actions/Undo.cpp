#include "Undo.h"

Undo::Undo(ApplicationManager* pApp):Action(pApp)
{
}

void Undo::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();






}

void Undo::Execute()
{
}
