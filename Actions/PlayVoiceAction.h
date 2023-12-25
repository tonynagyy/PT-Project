#pragma once
#ifndef PLAY_VOICE_ACTION_H
#define PLAY_VOICE_ACTION_H

#include "Action.h"



class PlayVoiceAction : public Action
{
	bool _enablevoice;


public:
	PlayVoiceAction(ApplicationManager* pApp);

	virtual void ReadActionParameters() ;


	virtual void Execute();

	virtual void undo() ;

	virtual Action* clone() const ;



};

#endif