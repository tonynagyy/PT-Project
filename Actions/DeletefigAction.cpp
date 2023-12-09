#include "DeletefigAction.h"

DeletefigAction::DeletefigAction(ApplicationManager* pApp): Action(pApp)
{
}

void DeletefigAction::ReadActionParameters()
{

    //Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	selectedfig = pManager->GetSelectedFigFigure();

}

void DeletefigAction::Execute()
{
	ReadActionParameters();

	if (selectedfig != nullptr)
	{
		pManager->DeleteFig(selectedfig);
	}


}
