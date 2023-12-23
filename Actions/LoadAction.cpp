#include "LoadAction.h"
#include "..\helper.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CSquare.h"



LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) 
{
}

void LoadAction::ReadActionParameters() {
	Output* outPtr = pManager->GetOutput();
	Input* inPtr = pManager->GetInput();

	outPtr->PrintMessage("plz entter the file name to load ");
	fileName = inPtr->GetSrting(outPtr);
	outPtr->ClearStatusBar();

}

void LoadAction::Execute()
{
	Output * outPtr = pManager->GetOutput();
	int counter = 0;
	string figType;
	CFigure* fig = NULL;

	ReadActionParameters();

	inFile.open(fileName);

	if (inFile.is_open()) {
		pManager->Clearall();
		inFile >> drawColor;
		inFile >> fillColor;
		outPtr->setCrntDrawColor(drawColor);
		outPtr->setCrntFillColor(fillColor);
		inFile >> counter;
		cout << counter << endl;

		for (int i = 0; i < counter; i++) {
			inFile >> figType;
			if (figType == "RECT") { // RECT SQ HEX TRIANG CIRC
				fig = new CRectangle;
			}
			else if (figType == "SQ") {
				fig = new CSquare;
			}
			else if (figType == "HEX") {
				fig = new CHexagon;
			}
			else if (figType == "TRIANG") {
				fig = new CTriangle;
			}
			else if (figType == "CIRC") {
				fig = new CCircle;
			}
			fig->Load(inFile);
			pManager->AddFigure(fig);
		}
		inFile.close();

	}	else {
		//Output* outPtr = pManager->GetOutput();
		outPtr->PrintMessage("file is not open or not found");
		//outPtr->ClearStatusBar();
	}

}

LoadAction* LoadAction::clone() const
{
	return NULL;
}

void LoadAction::undo()
{
}
