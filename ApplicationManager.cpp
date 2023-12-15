#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeletefigAction.h"
#include "Actions\PickFigAction.h"
#include "Actions/Undo.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	UndoCount = 0;
	RedoCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < 5; i++)
		Undoarray[i] = NULL;

	for (int i = 0; i < 5; i++)
		Redoarray[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *ptrToAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		this->UnSelect();
		ptrToAct = new AddRectAction(this);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		ptrToAct = NULL;
		DeleteAllRedos();
		break;
	
	case DRAW_CIRC:
		this->UnSelect();
		ptrToAct = new AddCircleAction(this);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;
	
	case DRAW_HEX:
		this->UnSelect();
		ptrToAct = new AddHexaAction(this);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;
	
	case DRAW_TRI:
		this->UnSelect();
		ptrToAct = new AddTriangleAction(this);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;
	
	case DRAW_SQ:
		this->UnSelect();
		ptrToAct = new AddSquareAction(this);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;

	case SELECT:
		ptrToAct = new SelectAction(this);
		ptrToAct->Execute();
		break;

	case DRAWING_AREA:
		this->UnSelect();
		break;
	
	case DEL:
		ptrToAct = new DeletefigAction(this); 
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		break;

	case TO_PLAY:
		this->UnSelect();
		pOut->CreatePlayToolBar();
		break;

	case TO_DRAW:
		pOut->CreateDrawToolBar();
		break;

	case PICK_FIG:
		ptrToAct = new PickFigAction(this);
		ptrToAct->Execute();
		break;
	
	case UNDO:
		ptrToAct = new Undo(this);
		ptrToAct->Execute();
		break;

	case REDO:
		ptrToAct = new Redo(this);
		ptrToAct->Execute();
		break;

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	
	//Execute the created action
	if (ptrToAct != NULL)
	{
		//ptrToAct->Execute();//Execute
		delete ptrToAct;	//You may need to change this line depending to your implementation
		ptrToAct = NULL;
	}
}

void ApplicationManager::SetInUndoList(Action* pAct)
{
	//Undoarray[UndoCount] = pAct->clone();
	if (pAct != NULL)
	{

		if (UndoCount <= 4)
		{
			Undoarray[UndoCount++] = pAct->clone();
			
		}
		else
		{
			// If the undo stack is full, remove the oldest action
			delete Undoarray[0];
			Undoarray[0] = NULL;
			for (int i = 0; i < 4; ++i)
			{
				Undoarray[i] = Undoarray[i + 1];
			}
			Undoarray[4] = pAct->clone();
		}

		delete Redoarray[RedoCount];
		Redoarray[RedoCount] = NULL;
	}
	//delete pAct;
	//pAct = NULL;
}
Action* ApplicationManager::GetLastUndo()
{
	if (UndoCount > 0)
	{
		Action* pAction = Undoarray[UndoCount - 1];
		//UndoCount--;
		return pAction;
	}
	else
		return NULL;
}

void ApplicationManager::SetInRedoList(Action* pAct)
{
	if (RedoCount < 4)
	{
		if (pAct != NULL)
		{
			Redoarray[RedoCount++] = pAct->clone();
			UndoCount--;
			delete Undoarray[UndoCount];
			Undoarray[UndoCount] = NULL;
			
		}
		else
			Redoarray[RedoCount] = NULL;
	}
	/*
	else
	{
		// If the undo stack is full, remove the oldest action
		Redoarray[0] = NULL;
		for (int i = 0; i < 4; ++i)
		{
			Redoarray[i] = Redoarray[i + 1];
		}
		Redoarray[4] = pAct;
	}*/

}
Action* ApplicationManager::GetLastRedo()
{
	if (RedoCount > 0)
	{
		Action* pAction = Redoarray[RedoCount - 1];
		RedoCount--;
		//UndoCount++;
		return pAction;
	}
	else
		return NULL;
}
void ApplicationManager::DeleteAllRedos()
{
	for (int i = 0; i < 5; i++)
	{
		if (Redoarray[i] != NULL)
		{
			delete Redoarray[i];
			Redoarray[i] = NULL;
		}
	}
	RedoCount = 0;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
		if (FigCount < MaxFigCount)
			FigList[FigCount++] = pFig;
}

// deleting the selected figure
void ApplicationManager::DeleteFig(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if ( (FigList[i]->GetNum() == pFig->GetNum()) && (FigList[i]->GetID() == pFig->GetID()) )
			{
				//delete FigList[i];
				//FigList[i] = NULL;
				FigList[i]->Sethidden(true);
			}
		}
	}

}
//get pointer to the selected figure
CFigure* ApplicationManager::GetSelectedFigFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->IsSelected())
			{
				SelectedFig = FigList[i];
				return SelectedFig;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->InFigure(x, y))
			{
				return FigList[i];
			}
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return nullptr;
}
void ApplicationManager::UnSelect()
{
	pOut->ClearStatusBar();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			FigList[i]->SetSelected(false);
		}
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL && ! FigList[i]->IfHidden())
		{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
	}
}
CFigure* ApplicationManager::RandomFigure()
{
	if (FigCount)
		if (FigList[rand() % FigCount] != nullptr)
			return FigList[rand() % FigCount];
		else
			RandomFigure();
	else
		return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];

	for (int i = 0; i < UndoCount && Undoarray[i]; i++)
	{
		delete Undoarray[i];
	}

	delete pIn;
	delete pOut;


}
