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
	CFigure* selectedfig = nullptr; // pointer to figure to be deleted 
public:
	DeletefigAction(ApplicationManager* pApp);
	DeletefigAction(const DeletefigAction& other);
	~DeletefigAction();
	DeletefigAction* clone() const override;
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo();
};
#endif;