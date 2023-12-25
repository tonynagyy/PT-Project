#include "PickClrFig.h"

PickClrFigAction::PickClrFigAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PickClrFigAction::ReadActionParameters()
{
	Fig = pManager->RandomFigure();
}

void PickClrFigAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (Fig)
		if (dynamic_cast<CRectangle*>(Fig) != nullptr)
		{
			string S1 = ColourToString(Fig);
			string S2 = "Pick the " + S1 + "Rectangles";

			pOut->PrintMessage(S2);
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier(), Fig->GetFillClr()) && !Exit);
		}

		else if (dynamic_cast<CCircle*>(Fig) != nullptr)
		{
			string S1 = ColourToString(Fig);
			string S2 = "Pick the " + S1 + "Circles";

			pOut->PrintMessage(S2);
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier(), Fig->GetFillClr()) && !Exit);
		}

		else if (dynamic_cast<CHexagon*>(Fig) != nullptr)
		{
			string S1 = ColourToString(Fig);
			string S2 = "Pick the " + S1 + "Hexagons";

			pOut->PrintMessage(S2);
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier(), Fig->GetFillClr()) && !Exit);
		}

		else if (dynamic_cast<CTriangle*>(Fig) != nullptr)
		{
			string S1 = ColourToString(Fig);
			string S2 = "Pick the " + S1 + "Triangles";

			pOut->PrintMessage(S2);
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier(), Fig->GetFillClr()) && !Exit);
		}

		else
		{
			string S1 = ColourToString(Fig);
			string S2 = "Pick the " + S1 + "Squares";

			pOut->PrintMessage(S2);
			do
			{
				if (CheckAns())
				{
					Fig->Sethidden(true);
					pManager->UpdateInterface();
				}

			} while (pManager->CheckPlay(Fig->GetIdentifier(), Fig->GetFillClr()) && !Exit);
		}
	else
		pOut->PrintMessage("There is no figures to play");

	pManager->DrawingBack();
	pManager->UpdateInterface();

	if (Exit)
	{
			int ClickedItemOrder = (P.x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_DRAWMODE: pManager->ExecuteAction(TO_DRAW); break;
			case ITM_FIGURE_TYPE_AND_FILL_COLOR: pManager->ExecuteAction(PICK_CLR_FIG); break;
			case ITM_FIGURE_FILL_COLOR: pManager->ExecuteAction(PICK_CLR); break;
			case ITM_FIGURE_TYBE: pManager->ExecuteAction(PICK_FIG); break;
			case EXIT_PLAY: pManager->ExecuteAction(GET_EXIT_PLAY); break;

			default:;
			}
	}
	else if (Fig)
	{		
		string msg = "Bravoooooo, You got " + to_string(CountCrt * 100 / (CountCrt + CountWrg)) + "%";
		pOut->PrintMessage(msg);
	}
}

bool PickClrFigAction::CheckAns()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string sentence1 = "The total correct answer is: ";
	string sentence2 = "   The total wrong answers is: ";



	pIn->GetPointClicked(P.x, P.y);

	if (P.y >= 0 && P.y < UI.ToolBarHeight && P.x < 5 * UI.MenuItemWidth)
		Exit = true;
	else
	{
		CheckFig = pManager->GetFigure(P.x, P.y);

		if (CheckFig && CheckFig->GetFillClr() == Fig->GetFillClr() && CheckFig->GetIdentifier() == Fig->GetIdentifier() && !CheckFig->IfHidden())
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
}

string PickClrFigAction::ColourToString(CFigure* F)
{
	if (F->IsFilled())
		if (F->GetFillClr() == BLACK)
			return "BLACK";
		else if (F->GetFillClr() == BLUE)
			return "BLUE";
		else if (F->GetFillClr() == ORANGE)
			return "ORANGE";
		else if (F->GetFillClr() == GREEN)
			return "GREEN";
		else if (F->GetFillClr() == YELLOW)
			return "YELLOW";
		else
			return "RED";
	else
		return "Non-Filled";
}

void PickClrFigAction::undo()
{
}

Action* PickClrFigAction::clone() const
{
	return new PickClrFigAction(*this);
}
