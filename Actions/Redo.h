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
	Action* Redoptr;	
public:
	Redo(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

	virtual void undo();

	virtual Action* clone() const override;


	~Redo();


};
#endif