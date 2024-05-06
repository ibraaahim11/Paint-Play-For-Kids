#ifndef BORDER_ACTION_H
#define BORDER_ACTION_H

#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"

class BorderAction : public Action
{
private:
	CFigure* SelectedFig; // Figure to be modified
	color Color; // Color to modify with
	int SelectedCount; // Selected count

	Output* pOut;
	Input* pIn;

public:
	BorderAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	// Execute
	virtual void Execute();
};

#endif