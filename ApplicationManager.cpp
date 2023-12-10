#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeletefigAction.h"
#include "Actions\PickFigAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
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
		break;
	
	case DRAW_CIRC:
		this->UnSelect();
		ptrToAct = new AddCircleAction(this);
		break;
	
	case DRAW_HEX:
		this->UnSelect();
		ptrToAct = new AddHexaAction(this);
		break;
	
	case DRAW_TRI:
		this->UnSelect();
		ptrToAct = new AddTriangleAction(this);
		break;
	
	case DRAW_SQ:
		this->UnSelect();
		ptrToAct = new AddSquareAction(this);
		break;

	case SELECT:
		ptrToAct = new SelectAction(this);
		break;

	case DRAWING_AREA:
		this->UnSelect();
		break;
	
	case DEL:
		ptrToAct = new DeletefigAction(this);
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
		ptrToAct->Execute();//Execute
		delete ptrToAct;	//You may need to change this line depending to your implementation
		ptrToAct = NULL;
	}
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
		if (FigList[i] == pFig)
		{
			FigList[i] = NULL;
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
				return FigList[i];
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
		if (FigList[i] != NULL)
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
	delete pIn;
	delete pOut;

}
