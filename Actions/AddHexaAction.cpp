#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp) {
}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center of Hexagon");

	//Read the center and store in point center
	pIn->GetPointClicked(center.x, center.y);

	
	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(center, HexaGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(R);
}
