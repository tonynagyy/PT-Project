#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :
	Action(pApp) , hexa(NULL), center(0,0)
{
}

void AddHexaAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center of Hexagon");
	pIn->GetPointClicked(center.x, center.y);
	
	/*set colors data*/
	HexaGfxInfo.isFilled = false;	//default is not filled
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexaAction::Execute()
{
	if (center.x == 0 && center.y == 0)
	{
		ReadActionParameters();
	}

	if (hexa == NULL)
	{
		hexa = new CHexagon(center, HexaGfxInfo);
	}

	pManager->AddFigure(hexa);
}

void AddHexaAction::undo()
{
	pManager->DeleteFig(hexa);
}

Action* AddHexaAction::clone() const
{
	return new AddHexaAction(*this);
}

AddHexaAction::~AddHexaAction()
{
	delete hexa;
	hexa = NULL;
}

