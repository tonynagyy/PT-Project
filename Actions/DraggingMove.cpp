#include "DraggingMove.h"

DraggingMove::DraggingMove(ApplicationManager* pApp) : Action(pApp)
{
}

void DraggingMove::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure to drag");
	pIn->GetPointClicked(P.x, P.y);

	Fig = pManager->GetFigure(P.x, P.y);

}

void DraggingMove::Execute()
{
	ReadActionParameters();
	pManager->UnSelect();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	while (!pIn->ClickingStatus(P.x, P.y))
	{
		Fig->SetMovable(true);
		Fig->move(P.x, P.y);
		if (!Fig->IsMovable())
			pOut->PrintMessage("Invalid Action");
		pManager->UpdateInterface();
		Sleep(1);
		pOut->ClearStatusBar();
	}
}



void DraggingMove::undo()
{
}

Action* DraggingMove::clone() const
{
	return nullptr;
}
