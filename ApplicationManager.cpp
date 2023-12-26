#include "ApplicationManager.h"
#include "Actions\StartRecAction.h"
#include "Actions\PlayRecAction.h"
#include "Actions\PlayvoiceAction.h"

ApplicationManager::ApplicationManager() :
	FigCount(0), UndoCount(0), RedoCount(0),undoable(false), Actualfigcounter(0)
	, actionsCount(0), InRecording(false), action(NULL),
	Startrecaction(NULL), PlayRecStatus(false), Playvoice(false),
	Undoarray{ NULL }, Redoarray{ NULL }, FigList{ NULL }, SelectedFig(NULL)
{
	pOut = new Output;
	pIn = pOut->CreateInput();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	return pIn->GetUserAction();
}

Action* ApplicationManager::getActionPtr() const 
{
	return action;
}

void ApplicationManager::setActionPtr(Action* action)
{
	this->action = action;
}

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *ptrToAct = NULL;

	switch (ActType)
	{
	case DRAW_RECT:
		this->UnSelect();
		ptrToAct = new AddRectAction(this, Playvoice);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);  // save the action in the undo list
		DeleteAllRedos();         // Delete redos in case of 
		break;
	case DRAW_CIRC:
		this->UnSelect();
		ptrToAct = new AddCircleAction(this, Playvoice);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);   
		DeleteAllRedos();         
		break;
	case DRAW_HEX:
		this->UnSelect();
		ptrToAct = new AddHexaAction(this, Playvoice);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;
	case DRAW_TRI:
		this->UnSelect();
		ptrToAct = new AddTriangleAction(this, Playvoice);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;
	case DRAW_SQ:
		this->UnSelect();
		ptrToAct = new AddSquareAction(this, Playvoice);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		break;
	case SELECT:
		this->UnSelect();
		ptrToAct = new SelectAction(this);
		ptrToAct->Execute();
		break;
	case DRAWING_AREA:
		this->UnSelect();
		pOut->ClearStatusBar();
		break;
	case DEL:
		ptrToAct = new DeletefigAction(this); 
		ptrToAct->Execute();
		if (undoable)/*Check if u Can Undo this Action like change color in the start of the program ??!*/
		{
			SetInUndoList(ptrToAct); 
		}
		DeleteAllRedos();
		break;
	case MOVE:
		ptrToAct = new MoveAction(this);
		ptrToAct->Execute();
		SetInUndoList(ptrToAct);
		DeleteAllRedos();
		this->UnSelect();
		break;
	case DRAGGING_MOVE:
		ptrToAct = new DraggingMove(this);
		ptrToAct->Execute();
		break;
	case RESIZE:
		ptrToAct = new ResizeAction(this);
		ptrToAct->Execute();
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
	case PICK_CLR:
		ptrToAct = new PickClrAction(this);
		ptrToAct->Execute();
		break;
	case PICK_CLR_FIG:
		ptrToAct = new PickClrFigAction(this);
		ptrToAct->Execute();
		break;
	case PLAYING_AREA:
		pOut->ClearStatusBar();
		break;
	case GET_EXIT_PLAY:
		Clearall();
		break;
	case UNDO:
		this->UnSelect();
		ptrToAct = new Undo(this);
		ptrToAct->Execute();
		break;
	case REDO:
		this->UnSelect();
		ptrToAct = new Redo(this);
		ptrToAct->Execute();
		break;
	case FILL_COLOUR: 
		ptrToAct = new SelectFillColour(this);
		ptrToAct->Execute();
		if (undoable) { SetInUndoList(ptrToAct); 
		}
		DeleteAllRedos();
		this->UnSelect();
		break;
	case DRAW_COLOUR:
		ptrToAct = new SelectDrawColour(this);
		ptrToAct->Execute();
		if (undoable) {
			SetInUndoList(ptrToAct); 
		}
		DeleteAllRedos();
		this->UnSelect();
		break;
	case SAVE:
		this->UnSelect();
		ptrToAct = new SaveAction(this);
		ptrToAct->Execute();
		break;
	case CLEAR:
		ptrToAct = new clearAll(this);
		ptrToAct->Execute();
		break;
		this->UnSelect();
		break;
	case LOAD:
		this->UnSelect();
		ptrToAct = new LoadAction(this);
		ptrToAct->Execute();
		break;
	case START_REC:
		ptrToAct = new StartRecAction(this);
		ptrToAct->Execute();
		break;
	case STOP_REC:
		pOut->PrintMessage("You cannot stop recording now");
		Sleep(1000);
		pOut->ClearStatusBar();
		break;
	case PLAY_REC:
		ptrToAct = new PlayRecAction(this);
		ptrToAct->Execute();
		this->UnSelect();
		break;

	case PLAY_VOICE:
		ptrToAct = new PlayVoiceAction(this);
		ptrToAct->Execute();
		this->UnSelect();
		break;

	case EXIT:
		Clearall();
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	/*actiosCount needed for the start Rec*/
	actionsCount++;

	/*Get StartRecAction to get this action needed to reach to the quqeue inside it*/
	if (dynamic_cast<StartRecAction*> (ptrToAct))
	{
		if (Startrecaction != NULL)
		{
			delete Startrecaction;
			Startrecaction = NULL;
		}
		Startrecaction = ptrToAct->clone();
	}

	if (ptrToAct != NULL && GetRecordStatus())// get Acopy of the Action If we Record Bcs it will be Deleted beneath
	{
		setActionPtr(ptrToAct->clone());
	}

	if (ptrToAct != NULL)
	{
		Setundoable(false);
		delete ptrToAct;
		ptrToAct = NULL;
	}
}

void ApplicationManager::SetInUndoList(Action* pAct)
{
	if (pAct != NULL)
	{
		if (UndoCount <= 4)
		{
			Undoarray[UndoCount++] = pAct->clone();
			
		}
		else
		{
			// If the undo stack is full, remove the oldest action
			if (Undoarray[0] != NULL) {
				delete Undoarray[0];
				Undoarray[0] = NULL;
			}

			for (int i = 0; i < 4; ++i)
			{
				Undoarray[i] = Undoarray[i + 1];
			}
			Undoarray[4] = pAct->clone();
		}

		if (RedoCount < 5)
		{
			if (Redoarray[RedoCount] != NULL)
			{
				delete Redoarray[RedoCount];
				Redoarray[RedoCount] = NULL;
			}
		}
		else
		{
			if (Redoarray[RedoCount - 1] != NULL)
			{
				delete Redoarray[RedoCount - 1];
				Redoarray[RedoCount - 1] = NULL;
			}
		}
	}
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
	if (RedoCount <= 4)
	{
		if (pAct != NULL)
		{
			Redoarray[RedoCount++] = pAct->clone();
			UndoCount--;
			if (Undoarray[UndoCount] != NULL)
			{
				delete Undoarray[UndoCount];
				Undoarray[UndoCount] = NULL;
			}
		}
		else
			Redoarray[RedoCount] = NULL;
	}
	
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
void ApplicationManager::Setundoable(bool b)
{
	undoable = b;
}
void ApplicationManager::DeleteFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			delete FigList[i];
			FigList[i] = NULL;
		}
	}
	FigCount = 0;
}
void ApplicationManager::Deleteundoarray()
{

	for (int i = 0; i < UndoCount && Undoarray[i]; i++) 
	{
		if (Undoarray[i] != NULL) 
		{
			delete Undoarray[i];
			Undoarray[i] = NULL;
		}
	}
	UndoCount = 0;
}
void ApplicationManager::Clearall() 
{
	DeleteFigList();
	Deleteundoarray();
	DeleteAllRedos();
	actionsCount = -1;    //to start rec again/ bcs it will be incrmenated in the excute
}

void ApplicationManager::SetInrecording(bool b)
{
	InRecording = b;
}

bool ApplicationManager::GetRecordStatus() {
	return InRecording;
}

Action* ApplicationManager::GetStartrecaction() {
	return Startrecaction;
}

void ApplicationManager::SetPlayrec(bool b) {
	PlayRecStatus = b;
}

bool ApplicationManager::GetPlayrecStatus() {
	return PlayRecStatus;
}

void ApplicationManager::SetPlayvoicestatus(bool b)
{
	Playvoice = b;	
}

bool ApplicationManager::Getplayvoicestatus() {
	return Playvoice;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (pFig->CalcArea() && pFig->IsDrawn())
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i] == NULL)
			{
				FigList[i] = pFig->clone();
				return;
			}
		}

		if (FigCount < MaxFigCount)
			FigList[FigCount++] = pFig->clone();
	}
	else
		pOut->PrintMessage("Unvalid Points Draw Again With Valid Points");
}

// deleting the selected figure
void ApplicationManager::DeleteFig(CFigure* pFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if ( /*FigList[i]->GetNum() == pFig->GetNum()) && */ (FigList[i]->GetID() == pFig->GetID()))
			{
				delete FigList[i];
				FigList[i] = NULL;
				//FigList[i]->Sethidden(true);
			}
		}
	}

}
void ApplicationManager::Changefillcolor(CFigure* pFig ,color clr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->GetID() == pFig->GetID())
			{
				FigList[i]->ChngFillClr(clr);
			}
		}
	}
}
void ApplicationManager::Changedrawcolor(CFigure* pFig, color clr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->GetID() == pFig->GetID())
			{
				FigList[i]->ChngDrawClr(clr);
			}
		}
	}
}
void ApplicationManager::Movefigure(CFigure* pFig, double& x, double& y)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->GetID() == pFig->GetID())
			{
				FigList[i]->move(x, y);
			}
		}
	}
}
//get pointer to the selected figure
CFigure* ApplicationManager::GetSelectedFigure()
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
	return nullptr;
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
	return nullptr;
}
void ApplicationManager::UnSelect()
{
	//pOut->ClearStatusBar();
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
void ApplicationManager::UpdateInterface()  const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL && !FigList[i]->IfHidden())
		{ 
				FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
	}
}
int ApplicationManager::getActFigCount() 
{
	Actualfigcounter = 0;

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			Actualfigcounter++;
		}
	}
	return (Actualfigcounter);
}
int ApplicationManager::getActionsCounter() const 
{
	return actionsCount;
}

/**
 * saveAll: save all figures in the the file
 * Parameters: ofstream &outFile
 * Return: void
 * Description: save all figures in the figlist into the file
*/
void ApplicationManager::saveAll(ofstream &outFile)  
{
	for (int i = 0; i < FigCount; i++) 
	{
		if (FigList[i] != NULL) 
		{
			FigList[i]->Save(outFile);
		}
	}
}
CFigure* ApplicationManager::RandomFigure()
{
	if (FigCount)
	{
		if (FigList[rand() % FigCount] != nullptr) 
		{
			return FigList[rand() % FigCount];
		}
		else
		{
			RandomFigure();
		}
	}
	else
	{
		return nullptr;
	}
}

bool ApplicationManager::CheckPlay(int I)
{
	for (int i = 0; i < FigCount; i++) 
	{
		if (FigList[i] && FigList[i]->GetIdentifier() == I && !FigList[i]->IfHidden())
		{
			return true;
		}
	}
	return false;
}

bool ApplicationManager::CheckPlay(color clr)
{
	for (int i = 0; i < FigCount; i++) 
	{
		if (FigList[i] && FigList[i]->GetFillClr() == clr && !FigList[i]->IfHidden())
		{
			return true;
		}
	}
	return false;
}

bool ApplicationManager::CheckPlay()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] && !FigList[i]->IsFilled() && !FigList[i]->IfHidden())
		{
			return true;
		}
	}
	return false;
}

bool ApplicationManager::CheckPlay(int I, color clr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] && FigList[i]->GetFillClr() == clr && FigList[i]->GetIdentifier() == I && !FigList[i]->IfHidden())
		{
			return true;
		}
	}
	return false;
}

void ApplicationManager::DrawingBack()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i])
		{
			FigList[i]->Sethidden(false);
		}
	}
}

Input* ApplicationManager::GetInput() const
{
	return pIn;
}
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
ApplicationManager::~ApplicationManager()
{
	Clearall();
	delete pIn;  
	delete pOut;
	if (Startrecaction != NULL)
	{
		delete Startrecaction;
		Startrecaction = NULL;
	}
	pIn = NULL;
	pOut = NULL;
}
