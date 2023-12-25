#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager *pApp, bool voice) :
	Action(pApp), PlayRectVoice(voice), rect(NULL), P1(0, 0), P2(0, 0)
{
}

AddRectAction::AddRectAction(const AddRectAction& other)
	:Action(other), PlayRectVoice(other.PlayRectVoice), rect(NULL),
	P1(other.P1), P2(other.P2), RectGfxInfo(other.RectGfxInfo)
{
	if (other.rect != NULL)
	{
		//rect = new CRectangle(*othjer.rect);
		rect = static_cast<CRectangle*>(other.rect->clone());
	}
}

void AddRectAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (PlayRectVoice)          // if Voice is enabled then play the voice of rectangle
	{
		PlaySound(TEXT("Voices\\Rectvoice.wav.wav"), NULL, SND_ASYNC);
		//PlaySound(0, 0, 0);
	}
	 
	pOut->PrintMessage("New Rectangle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Rectangle: Click at second corner");
	pIn->GetPointClicked(P2.x, P2.y);

	/*set colors data*/
	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddRectAction::Execute() 
{
	if (P1.x == 0 && P1.y == 0 && P2.x == 0 && P2.y == 0)
	{
		ReadActionParameters();
	}
	
	if (rect == NULL)
	{// if rect == null then we need to make a new one bcs initally it is null
		 rect = new CRectangle(P1, P2, RectGfxInfo);
		 //sice rect is something new so we need to make a copy constructor
	}

	pManager->AddFigure(rect);
	//delete R;
	//R = NULL;
}

void AddRectAction::undo()
{
	pManager->DeleteFig(rect);
}

Action* AddRectAction::clone() const
{
	return new AddRectAction(*this);
}

AddRectAction::~AddRectAction()
{
	delete rect;
	rect = NULL;
}
