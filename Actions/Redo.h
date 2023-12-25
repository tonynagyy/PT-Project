#pragma once
#ifndef REDO_H
#define REDO_H

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\defs.h"
#include"Undo.h"



class Redo : public Action
{
public:
	/*
	Action* redoStack[5];
	int redoIndex;
	Undo* undoing;
	*/
	Action* Redoptr;	// pointer to last Redoable action
public:
	Redo(ApplicationManager* pApp);
	~Redo();

	virtual void ReadActionParameters() override;
	virtual void Execute() override;
	virtual void undo() override;
	Action* clone() const override;
};
#endif