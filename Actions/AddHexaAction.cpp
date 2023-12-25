#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp, bool voice) :
	Action(pApp) , hexa(NULL), center(0,0), PlayHexaVoice(voice)
{
}

AddHexaAction::AddHexaAction(const AddHexaAction& other) :
	Action(other), hexa(NULL), center(other.center), HexaGfxInfo(other.HexaGfxInfo), PlayHexaVoice(other.PlayHexaVoice)
{
	if (other.hexa != NULL)
	{
		hexa = static_cast<CHexagon*>(other.hexa->clone());
	}
}

void AddHexaAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (PlayHexaVoice)          // if Voice is enabled then play the voice of rectangle
	{
		PlaySound(TEXT("Voices\\Rectvoice.wav.wav"), NULL, SND_ASYNC);
		//PlaySound(0, 0, 0);
	}

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

