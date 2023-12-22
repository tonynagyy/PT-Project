#include "PickFigAction.h"

PickFigAction::PickFigAction(ApplicationManager* pApp) : Action(pApp)
{}

void PickFigAction::ReadActionParameters()
{
	Fig = pManager->RandomFigure();	
}

void PickFigAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (Fig)
		if (dynamic_cast<CRectangle*>(Fig) != nullptr)
		{
			pOut->PrintMessage("Pick the rectangles");
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier()));
		}

		else if (dynamic_cast<CCircle*>(Fig) != nullptr)
		{
			pOut->PrintMessage("Pick the circle");
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier()));
		}

		else if (dynamic_cast<CHexagon*>(Fig) != nullptr)
		{
			pOut->PrintMessage("Pick the hexagon");
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier()));
		}

		else if (dynamic_cast<CTriangle*>(Fig) != nullptr)
		{
			pOut->PrintMessage("Pick the triangle");
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier()));
		}

		else
		{
			pOut->PrintMessage("Pick the square");
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier()));
		}
	else
		pOut->PrintMessage("There is no figures to play");

	pManager->DrawingBack();

}

bool PickFigAction::CheckAns()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string sentence1 = "The total correct answer is: ";
	string sentence2 = "   The total wrong answers is: ";
	
	

	pIn->GetPointClicked(P.x, P.y);
	CheckFig = pManager->GetFigure(P.x, P.y);

	if (CheckFig && CheckFig->GetIdentifier() == Fig->GetIdentifier() && !CheckFig->IfHidden())
	{
		Fig = CheckFig;
		string msg1 = sentence1 + to_string(++CountCrt) + sentence2 + to_string(CountWrg);
		pOut->PrintMessage(msg1);
		return true;
	}
	else
	{
		string msg2 = sentence1 + to_string(CountCrt) + sentence2 + to_string(++CountWrg);
		pOut->PrintMessage(msg2);
		return false;
	}
}

void PickFigAction::undo()
{
}

Action* PickFigAction::clone() const
{
	return new PickFigAction(*this);
}
