#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager *pApp, bool voice) :Action(pApp), PlayRectVoice(voice)
{
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;

	rect = NULL;
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (PlayRectVoice)          // if Voice is enabled then play the voice of rectangle
	{
		PlaySound(("Voices\Rectvoice.wav"), NULL, SND_SYNC);
		//PlaySound(0, 0, 0);

	}
	 
	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	if (P1.x == 0 && P1.y == 0 && P2.x == 0 && P2.y == 0)
	{
		ReadActionParameters();
	}
	
	if (rect == NULL)
	{
		//Create a rectangle with the parameters read from the user
		 rect = new CRectangle(P1, P2, RectGfxInfo);
		//rect = R->clone();
	 }


	//Add the rectangle to the list of figures
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
