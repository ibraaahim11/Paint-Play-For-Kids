#pragma once

#ifndef SWITCH_TO_PLAY_H
#define SWITCH_TO_PLAY_H

#include"Action.h"

class Switchtoplay :public Action
{
public:
	Switchtoplay(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();



};
#endif