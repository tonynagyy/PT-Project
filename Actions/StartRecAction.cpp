#include "StartRecAction.h"
#include <iostream>
using std::endl;//for testing into the console
using std::cout;//for testing into the console

/*
* StartRecAction::StartRecAction Constructor
* @param ApplicationManager pointer
* Description: Constructor to initialize the queue and the front and rear
* intitally u cannot rec
*/
StartRecAction::StartRecAction(ApplicationManager* pApp)
	:Action(pApp), canStartRec(false), front(-1), rear(-1), queue{NULL}
{
}

/*
* StartRecAction::StartRecAction Copy Constructor
* @param StartRecAction reference
* Description: Copy Constructor to copy the queue and the front and rear
* Needed for undo and redo to take a clone of the action
*/
StartRecAction::StartRecAction(const StartRecAction& other)
	:Action(other.pManager), canStartRec(other.canStartRec), 
	front(other.front), rear(other.rear), queue{nullptr}
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (other.queue[i] != nullptr)
		{
			queue[i] = other.queue[i]->clone();
		}
	}
}

/*
* StartRecAction::StartRecAction Destructor
* Description: Destructor to delete the queue if not empty
*/
StartRecAction::~StartRecAction()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (queue[i] != NULL)
		{
			delete queue[i];
			queue[i] = NULL;
		}
	}
}

/*
* StartRecAction::ReadActionParameters
* Description: Read the parameters required for the action to execute AKA can u start rec or not
*/
void StartRecAction::ReadActionParameters() 
{
	canStartRec = canStartRecd();
}

/*
* StartRecAction::Execute
* Description: Execute the action if valid
* add the action to the queue if valid
* if not valid print err msg
*/
void StartRecAction::Execute() 
{
	Output* outPut = pManager->GetOutput();
	Input* inPut = pManager->GetInput();
	Action* action = nullptr;
	ActionType ActType;
	bool isValidAction = false;

	ReadActionParameters();

	if (canStartRec) 
	{
		pManager->SetInrecording(true);/*if he can rec put the rec bcs we clone to avoid mem leak*/

		outPut->PrintMessage("Recording Started");
		Sleep(1000);
		outPut->ClearStatusBar();
		outPut->PrintMessage("Remeber that u have max of 20 rec excluding start stop play save load switch exit");
		Sleep(1000);
		outPut->ClearStatusBar();

		ActType = pManager->GetUserAction();
		
		// if he stopped recording just after start rec
		if (ActType == STOP_REC || ActType == CLEAR)
		{
			outPut->PrintMessage("Recording Stopped");
			Sleep(1000);
			outPut->ClearStatusBar();
			pManager->SetInrecording(false);
			return;
		}

		// if valid action enqueue it if not donot enqueue it till stop rec or get 20 valid rec
		while (ActType != STOP_REC && !isFull() && ActType != CLEAR)
		{
			isValidAction = ckeckActionValidity(ActType);
			if (isValidAction)
			{
				pManager->ExecuteAction(ActType);
				action = pManager->getActionPtr();
				if (action == NULL)
				{
					cout << "Action is nullptr" << endl;//for testing
				}
				else 
				{
					enqueue(action);
					pManager->UpdateInterface(); //update the interface after each action bcs we execute it 
				}
			}
			ActType = pManager->GetUserAction();
		}
		pManager->SetInrecording(false);

		if (ActType == STOP_REC)
		{
			outPut->PrintMessage("Recording Stopped");
		}
		else if (ActType == CLEAR)
		{
			outPut->PrintMessage("Clear all");
			Sleep(1000);
			outPut->ClearStatusBar();
			pManager->ExecuteAction(ActType);
			pManager->UpdateInterface();
			this->~StartRecAction();
		}
		else if (isFull())
		{
			outPut->PrintMessage("Max number of rec reached u cannot rec anymore");
		}
			Sleep(1000);
			outPut->ClearStatusBar();
			return;
	}
	else 
	{
		outPut->PrintMessage("Failed u cannot Rec now just after clear all or at start");
		Sleep(1000);
		outPut->ClearStatusBar();
		return;
	}
}

void StartRecAction::undo()
{
}

/*
*StartRecAction::clone Clone the Action via Non default Copy Constructor
*Description: clone of start to play it mulitple times needed for play
*Return: Return A clone of start Rec Action
*/
StartRecAction* StartRecAction::clone() const 
{
	return (new StartRecAction(*this));
}

/*
* canStartRecd to check if the action is valid or not
* @return bool
* Description: checks if the action count is 0 or not if 0 means at the start of the program
* or after clear action so it's valid else
*/
bool StartRecAction::canStartRecd()
{
	int count = 0;

	count = pManager->getActionsCounter();
	if (count == 0)
	{
		return (true);
	}
	return (false);
}

/*
* StartRecAction::CkeckActionValidity Checks if the action Can be Recorded or not
* @type: Action type
* Return: True if Valid false if Not
* Descriprion: ckeck if there is some action that can be rec or not and print err msg
*/
bool StartRecAction::ckeckActionValidity(const ActionType& type) const 
{
	switch (type)
	{
	case EXIT:
		break;
	case SAVE:
		break;
	case LOAD:
		break;
	case TO_PLAY:
		break;
	case PLAYING_AREA:
		break;
	case STATUS:
		break;
	case DRAWING_AREA:
		break;
	case EMPTY:
		break;
	case START_REC:
		break;
	case PLAY_VOICE:
		break;
	case RESIZE:
		break;
	case DRAGGING_MOVE:
		break;
	default:
		return (true);
	}
	pManager->GetOutput()->PrintMessage("Action cannot be recorded");
	Sleep(1000);
	pManager->GetOutput()->ClearStatusBar();
	return (false);
}

/*
* StartRecAction::isEmpty
* @return bool
* Description: checks if the queue is empty or not
* */
bool StartRecAction::isEmpty() const 
{
	return ((rear == -1) && (front == -1));
}

/*
* StartRecAction::isFull
* @return bool
* Description: checks if the queue is full or not
*/
bool StartRecAction::isFull() const 
{
	return (rear == (MAX_SIZE - 1));
}

/*
* StartRecAction::enqueue
* @param Action pointer
* Description: enqueue the action in the queue if not full
*/
void StartRecAction::enqueue(Action *action)
{
	if (action == nullptr) 
	{
		return;
	}
	else 
	{
		if (isFull()) 
		{
			return;
		}
		else if (isEmpty()) 
		{
			front = rear = 0;
		}
		else 
		{
			rear++;
		}
		queue[rear] = action;
	}
}

/*
* StartRecAction::dequeue
* @return Action pointer
* Description: dequeue the front of the queue or nullptr if empty
* */
Action* StartRecAction::dequeue() 
{
	Action* action = nullptr;

	if (isEmpty()) 
	{
		return (action);//nullptr if empty
	}
	else if (front == rear) 
	{
		action = queue[front];
		front = -1;
		rear = -1;
	}
	else 
	{
		action = queue[front];
		front++;
	}
	return (action);
}


/*
* StartRecAction::displayQueue for testing
* Description: displpays the queue from front to rear
*/
void StartRecAction::displayQueue() const 
{
	if (isEmpty()) 
	{
		return;
	}
}

/*
* StartRecAction::getFront get the front of the queue
* @return Action pointer
* Description: get the front of the queue or nullptr if empty
*/
Action* StartRecAction::getFront() const 
{
	if (isEmpty()) 
	{
		return nullptr;
	}
	return (queue[front]);
}

/*
* StartRecAction::getRear get the rear of the queue
* @return Action pointer
* Description: get the rear of the queue or nullptr if empty
*/
Action* StartRecAction::getRear() const 
{
	if (isEmpty()) 
	{
		return nullptr;
	}
	return (queue[rear]);
}

/*
* StartRecAction::getQueueSize get the size of the queue
* @return int
* Description: get the size of the queue
*/
int StartRecAction::getQueueSize() const 
{
	return (rear - front + 1);
}

/*
* StartRecAction::setFrontIndex set the front of the queue
* @param int
* Description: set the front of the queue needed for PlayRecAction multiple times
*/
void StartRecAction::setFrontIndex(int idx)
{
	front = idx;
}

/*
* StartRecAction::setRearIndex set the rear of the queue
* @param int
* Description: set the rear of the queue needed for PlayRecAction multiple times
*/
void StartRecAction::setRearIndex(int idx)
{
	rear = idx;
}



