#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H

#include "Actions/Action.h"
#include "Figures\CFigure.h"

//Add Delete Action class
class DeleteAction : public Action
{
private:
	int SelectedCount; // Number of figures selected
	
public:
	DeleteAction(ApplicationManager* pApp);

	//Reads parameters
	virtual void ReadActionParameters();

	//Deletes icons
	virtual void Execute();
};

#endif#pragma once
