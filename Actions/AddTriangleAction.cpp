#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) : 
	Action(pApp), P1(0, 0), P2(0,0), P3(0, 0), triangle(NULL)
{
}

void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Triangle: Click at second point");
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third point");
	pIn->GetPointClicked(P3.x, P3.y);

	/*Setting Draw colors */
	triangleGfxInfo.isFilled = false;	//default is not filled
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
		triangle = new CTriangle(P1, P2, P3, triangleGfxInfo);
	}

	pManager->AddFigure(triangle);
}

void AddTriangleAction::undo()
{
	pManager->DeleteFig(triangle);
}

Action* AddTriangleAction::clone() const
{
	return new AddTriangleAction(*this);
}

AddTriangleAction::~AddTriangleAction()
{
	delete triangle;
	triangle = NULL;
}
