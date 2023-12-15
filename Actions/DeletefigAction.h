#ifndef DELETEACTION_H
#define DELETEACTION_H


#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"


class DeletefigAction : public Action
{
	CFigure* selectedfig = nullptr;



public:
	DeletefigAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void undo();
	
	virtual Action* clone() const override;


};
#endif;