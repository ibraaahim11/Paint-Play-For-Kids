#pragma once
#ifndef ADD_CLEARALL_ACTION_H
#define ADD_CLEARALL_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"

//Clear All Action class
class ClearAllAction : public Action
{
public:
	ClearAllAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
};

#endif