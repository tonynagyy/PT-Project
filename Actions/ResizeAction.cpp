#include "ResizeAction.h"

ResizeAction::ResizeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure to resize");
	pIn->GetPointClicked(P.x, P.y);

	Fig = pManager->GetFigure(P.x, P.y);

	if(Fig)
		int FigCorner = Fig->SelectCorner(P.x, P.y);
	else
		pOut->PrintMessage("There is no figure selected");
		
}

void ResizeAction::Execute()
{
	ReadActionParameters();
	pManager->UnSelect();  // To hide the Magenta colour

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (Fig)
		while (!pIn->ClickingStatus(P.x, P.y))
		{
			Fig->Resize(P.x, P.y, Valid, FigCorner);
			if(Valid)
			{
				pManager->UpdateInterface();
				Sleep(10);
				pOut->ClearStatusBar();
			}
			else
				pOut->PrintMessage("Invalid Action");
		}

}

void ResizeAction::undo()
{

}

Action* ResizeAction::clone() const
{
	return nullptr;
}
