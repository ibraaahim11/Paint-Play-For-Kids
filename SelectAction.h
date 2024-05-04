#pragma once
#ifndef SELECT_H
#define SELECT_H
#include "Actions/Action.h"

class SelectAction : public Action
{
private:
	Point P1; //Point clicked

public:
	SelectAction(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute();
};

#endif