#ifndef MOVE_ACTION_H
#define	 MOVE_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"
#include "..\ApplicationManager.h"

class MoveAction : public Action{
	private:
		Point NewcenterPoint;
		Point InicenterPoint;
		CFigure* Selectedfig;
	public:
		MoveAction(ApplicationManager* pApp);
		MoveAction(const MoveAction&);
		void ReadActionParameters() override;
		void Execute() override;
		void undo() override;
		Action* clone() const override;
		~MoveAction();
};
#endif
