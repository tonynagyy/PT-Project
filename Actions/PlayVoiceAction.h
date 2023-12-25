#pragma once
#ifndef PLAY_VOICE_ACTION_H
#define PLAY_VOICE_ACTION_H

#include "Action.h"



class PlayVoiceAction : public Action
{
	bool _enablevoice;


public:
	PlayVoiceAction(ApplicationManager* pApp);

	void ReadActionParameters() override;
	void Execute() override;
	void undo()  override;
	Action* clone() const override;
};

#endif