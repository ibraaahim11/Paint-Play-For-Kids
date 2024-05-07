#pragma once
#ifndef SOUND_ACTION_H
#define SOUND_ACTION_H

#include "Actions/Action.h"

//Add Sound Action class
class SoundAction : public Action
{
private:
	ActionType action;
	const char* file;
	bool SoundOn;

public:
	SoundAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();


	virtual void Execute();
};

#endif