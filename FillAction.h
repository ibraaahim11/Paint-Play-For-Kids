#ifndef FILL_ACTION_H
#define FILL_ACTION_H

#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"

class FillAction : public Action
{
private:
	CFigure* SelectedFig; // Figure to be modified
	color Color; // Color to modify with
	int SelectedCount; // Selected count

	Output* pOut;
	Input* pIn;

public:
	FillAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	// Execute
	virtual void Execute();
};

#endif