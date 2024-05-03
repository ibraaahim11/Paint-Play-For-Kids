#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Actions/Action.h"

//Add Square Action class
class AddSquareAction : public Action
{
private:
	Point P1, P2; //Square center and size
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();
};

#endif