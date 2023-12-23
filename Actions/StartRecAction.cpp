#include "StartRecAction.h"
#include <iostream>
using std::cout;
using std::endl;

/*
* StartRecAction::StartRecAction Constructor
* @param ApplicationManager pointer
* Description: Constructor to initialize the queue and the front and rear
* intitally u cannot rec 
*/
StartRecAction::StartRecAction(ApplicationManager* pApp) 
	: Action(pApp) , canStartRec(false), front(-1), rear(-1){
}

/*
* StartRecAction::ReadActionParameters
* Description: Read the parameters required for the action to execute AKA can u start rec or not
*/
void StartRecAction::ReadActionParameters() {
	canStartRec = canStartRecd();
}

/*
* StartRecAction::Execute
* Description: Execute the action if valid
* add the action to the queue if valid
* if not valid print err msg
*/
void StartRecAction::Execute() {
	Output * outPut = pManager->GetOutput();
	Input * inPut = pManager->GetInput();
	ActionType ActType;
	//Point P;
	bool isValidAction = false;
	Action *action = nullptr;

	ReadActionParameters();

	if (canStartRec) {
		outPut->PrintMessage("Recording Started click the ope reme u cannot use");
		cout << "Recording Started click the ope reme u cannot use" << endl;
		outPut->PrintMessage("remeber that u have max of 20 rec excluding start stop play save load switch exit");
		cout << "remeber that u have max of 20 rec excluding start stop play save load switch exit" << endl;
		ActType = pManager->GetUserAction();


		outPut->ClearStatusBar();
		outPut->ClearStatusBar();
		// if valid action enqueue it if not donot enqueue it till stop rec or get 20 valid rec

		if (ActType == STOP_REC) {
			outPut->PrintMessage("Recording Stopped");
			cout << "Recording Stopped" << endl;
			outPut->ClearStatusBar();
			return;
		}

		while (ActType != STOP_REC && !isFull()) {
			isValidAction = ckeckActionValidity(ActType);
			if (isValidAction) {
				//action = pManager->getActionPtr(ActType);
				pManager->ExecuteAction(ActType);
				action = pManager->getActionPtr();
				if (action == NULL) {
					cout << "Action is nullptr" << endl;
				}
				else {
					enqueue(action);
					outPut->PrintMessage("Action Recorded");
					cout << "Action Recorded" << endl;
					outPut->ClearStatusBar();
					pManager->UpdateInterface();//update the interface after each action delete this if u want
				}
			}
			ActType = pManager->GetUserAction();
		}
		if (ActType == STOP_REC) {
			cout << "Recording Stopped" << endl;	
			return;
		}
		
	} else {
		outPut->PrintMessage("Failed u cannot Rec now just after clear all or At the start of this shit");
		cout << "you cannot record mother fukcker\n";
		outPut->ClearStatusBar();
		return;
	}
}

void StartRecAction::undo() {
}

/*
* StartRecAction::Clone clone this action
*/
StartRecAction* StartRecAction::clone() const {
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
	if (count == 0) {
		return (true);
	}
		return (false);
}

/*
* StartRecAction::CkeckActionValidity Checks if the action Can be Recorded or not 
* @type Action type para
* Descriprion ckeck if there is some action that can be rec or not and print err msg
*/
bool StartRecAction::ckeckActionValidity(const ActionType& type) const{
		switch (type) {
			case EXIT:
				cout <<  "You cannot exit in the middle of recording" << endl;
				break;
			case SAVE:
				cout << "You cannot save in the middle of recording" << endl;
				break;
			case LOAD:
				cout << "You cannot load in the middle of recording" << endl;
				break;
			case PLAYING_AREA:
				cout << "You cannot play in the middle of recording" << endl;
				break;
			case STATUS:
				cout << "You cannot click on the status bar in the middle of recording" << endl;
				break;
			case DRAWING_AREA:
				cout << "You cannot click on the drawing area in the middle of recording" << endl;
				break;
			case EMPTY:
				cout << "You cannot click on the empty area in the middle of recording" << endl;
				break;
			case START_REC:
				cout << "You cannot start recording in the middle of recording" << endl;
				break;
			default:
				return true;
		}
		return false;
}

/*
* StartRecAction::isEmpty
* @return bool
* Description: checks if the queue is empty or not
* */
bool StartRecAction::isEmpty() const {
	return (rear == -1 && front == -1);
}

/*
* StartRecAction::isFull
* @return bool
* Description: checks if the queue is full or not
*/
bool StartRecAction::isFull() const {
	return (rear == MAX_SIZE - 1);
}

/*
* StartRecAction::enqueue
* @param Action pointer
* Description: enqueue the action in the queue if not full
* 
* */
void StartRecAction::enqueue(Action* action) {
	if (action == nullptr) {
		cout << "Action is nullptr" << endl;
		return;
	} else {
		if (isFull()) {
			cout << "Queue is full" << endl;
			return;
		}
		else if (isEmpty()) {
			front = rear = 0;
		} else {
			rear++;
		}
		queue[rear] = action->clone();
	}
}


/*
* StartRecAction::dequeue
* @return Action pointer
* Description: dequeue the front of the queue or nullptr if empty
* */
Action* StartRecAction::dequeue() {
	Action* action = nullptr;

	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return (action);//nullptr if empty
	}
	else if (front == rear) {
		action = queue[front];
		front = -1;
		rear = -1;
	} else {
		action = queue[front];
		front++;
	}
	return (action);
}


/*
* StartRecAction::displayQueue for testing
* Description: displpays the queue from front to rear
*/

void StartRecAction::displayQueue() const {
	if (isEmpty()) {
		cout << "Queue is empty no display" << endl;
		return;
	}

	//for (int i = front; i <= rear; i++) {
	//	cout << queue[i] << " ";
	//}
}

/*
* StartRecAction::getFront get the front of the queue
* @return Action pointer
* Description: get the front of the queue or nullptr if empty
*/
Action* StartRecAction::getFront() const {
	if (isEmpty()) {
		cout << "Queue is empty no front" << endl;
		return nullptr;
	}
	return (queue[front]);
}

/*
* StartRecAction::getRear get the rear of the queue
* @return Action pointer
* Description: get the rear of the queue or nullptr if empty
*/
Action* StartRecAction::getRear() const {
	if (isEmpty()) {
		cout << "Queue is empty no rear" << endl;
		return nullptr;
	}
	return (queue[rear]);
}

/*
* StartRecAction::getQueueSize get the size of the queue
* @return int
* Description: get the size of the queue
*/
int StartRecAction::getQueueSize() const {
	return (rear - front + 1);
}



