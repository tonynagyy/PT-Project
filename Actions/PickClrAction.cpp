#include "PickClrAction.h"

PickClrAction::PickClrAction(ApplicationManager* pApp) : Action(pApp)
{}

void PickClrAction::ReadActionParameters()
{
	Fig = pManager->RandomFigure();	
}

void PickClrAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if(Fig)
		if (Fig->IsFilled())
			if (Fig->GetFillClr() == BLACK)
			{
				pOut->PrintMessage("Pick black figures");
				do
				{
					if (CheckAns())
					{
						Fig->Sethidden(true);
						pManager->UpdateInterface();
					}

				} while (pManager->CheckPlay(BLACK));
			}

			else if (Fig->GetFillClr() == ORANGE)
			{
				pOut->PrintMessage("Pick orange figures");
				do
				{
					if (CheckAns())
					{
						Fig->Sethidden(true);
						pManager->UpdateInterface();
					}

				} while (pManager->CheckPlay(ORANGE));
			}

			else if (Fig->GetFillClr() == BLUE)
			{
				pOut->PrintMessage("Pick blue figures");
				do
				{
					if (CheckAns())
					{
						Fig->Sethidden(true);
						pManager->UpdateInterface();
					}

				} while (pManager->CheckPlay(BLUE));
			}

			else if (Fig->GetFillClr() == RED)
			{
				pOut->PrintMessage("Pick red figures");
				do
				{
					if (CheckAns())
					{
						Fig->Sethidden(true);
						pManager->UpdateInterface();
					}

				} while (pManager->CheckPlay(RED));
			}

			else if (Fig->GetFillClr() == YELLOW)
			{
				pOut->PrintMessage("Pick yellow figures");
				do
				{
					if (CheckAns())
					{
						Fig->Sethidden(true);
						pManager->UpdateInterface();
					}

				} while (pManager->CheckPlay(YELLOW));
			}

			else
			{
				pOut->PrintMessage("Pick green figures");
				do
				{
					if (CheckAns())
					{
						Fig->Sethidden(true);
						pManager->UpdateInterface();
					}

				} while (pManager->CheckPlay(GREEN));
			}
		else 
		{
			pOut->PrintMessage("Pick non-filled figures");
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay());
		}
	else
		pOut->PrintMessage("There is no figures to play");

	pManager->DrawingBack();

}

bool PickClrAction::CheckAns()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string sentence1 = "The total correct answer is: ";
	string sentence2 = "   The total wrong answers is: ";
	
	

	pIn->GetPointClicked(P.x, P.y);
	CheckFig = pManager->GetFigure(P.x, P.y);

	if (CheckFig && CheckFig->GetFillClr() == Fig->GetFillClr() && !CheckFig->IfHidden())
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

void PickClrAction::undo()
{
}

Action* PickClrAction::clone() const
{
	return new PickClrAction(*this);
}
