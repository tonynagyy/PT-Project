#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "windows.h"
#include "mmsystem.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
public:

	Action(ApplicationManager *pApp) 
	{
		pManager = pApp;
	}

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() = 0;

	//Execute action (code depends on action type)
	virtual void Execute() = 0;
	virtual void undo() = 0;
	virtual Action* clone() const = 0;
	virtual ~Action() = default;
};

#endif