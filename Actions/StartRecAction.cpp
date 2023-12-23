#include "StartRecAction.h"
#include <iostream>
using std::cout;
using std::endl;

StartRecAction::StartRecAction(ApplicationManager* pApp) 
	: Action(pApp) , isValid(false), front(-1), rear(-1), size(0) {
}

void StartRecAction::ReadActionParameters() {
	isValid = ckeckValidty();
}

void StartRecAction::Execute() {
	Output * outPut = pManager->GetOutput();
	Input * inPut = pManager->GetInput();
	ActionType ActType;
	Point P;
	bool isValidAction = false;

	ReadActionParameters();
	if (isValid) {
		outPut->PrintMessage("Recording Started click the ope reme u cannot use");
		outPut->ClearStatusBar();
		outPut->PrintMessage("remeber that u have max of 20 rec excluding start stop play save load switch exit");
		outPut->ClearStatusBar();
		ActType = pManager->GetUserAction();
		isValidAction = ckeckActionValidity(ActType);
		



	} else {
		outPut->PrintMessage("Failed u cannot Rec now just after clear all or At the start of this shit");
		outPut->ClearStatusBar();
		return;
	}
}

void StartRecAction::undo() {
}

StartRecAction* StartRecAction::clone() const {
	return (new StartRecAction(*this));
}
/*
* StartRecAction::ckeckValidty to check if the action is valid or not
* @return bool
* Description: checks if the action count is 0 or not if 0 means at the start of the program 
* or after clear action so it's valid else
*/

bool StartRecAction::ckeckValidty()
{
	int count = 0;
	count = pManager->getActionsCounter();
	if (count == 0) {
		return true;
	}
		return false;
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
