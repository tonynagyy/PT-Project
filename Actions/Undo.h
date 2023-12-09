#ifndef UNDO_H
#define UNDO_H

#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"


#define max 200 


class Undo : public Action
{
	CFigure* action_list[max];
	int actioncount;
	CFigure* undoarray[5];
	int topindex;

 public:
	 Undo(ApplicationManager* pApp);


	 virtual void ReadActionParameters();


	 virtual void Execute();


};
#endif