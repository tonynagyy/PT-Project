#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) : Action(pApp) 
{
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;
	P3.x = 0;
	P3.y = 0;

	triangle = NULL;
}

void AddTriangleAction::ReadActionParameters()
{//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	
	pOut->PrintMessage("New Triangle: Click at third point");

	//Read 3rd point and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	triangleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	triangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	triangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	if (P1.x == 0 && P1.y == 0 && P2.x == 0 && P2.y == 0 && P3.x == 0 && P3.y == 0)
	{
		ReadActionParameters();
	}
	
	if (triangle == NULL)
	{
		//Create a triangle with the parameters read from the user
		CTriangle* T = new CTriangle(P1, P2, P3, triangleGfxInfo);
		triangle = T;
	}

	//Add the rectangle to the list of figures
	triangle->Sethidden(false);
	pManager->AddFigure(triangle);


}

void AddTriangleAction::undo()
{
	triangle->Sethidden(true);
}

Action* AddTriangleAction::clone() const
{
	return new AddTriangleAction(*this);
}

AddTriangleAction::~AddTriangleAction()
{
	delete triangle;
}
