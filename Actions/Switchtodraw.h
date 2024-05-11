#pragma once
#ifndef SWITCH_TO_DRAW_H
#define SWITCH_TO_DRAW_H

#include"Action.h"
class Switchtodraw :public Action {
public:
	Switchtodraw(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
};
#endif
