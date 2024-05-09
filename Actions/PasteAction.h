#include "Action.h"
#include "..\Figures\CFigure.h"


class PasteAction : public Action
{
	CFigure* Cptr; //points to clipBoard
	char PType; //Type of pasted Figure
	Point p; //user click for paste


public:

	PasteAction(ApplicationManager* pApp);
	//Reads Paste parameters
	virtual void ReadActionParameters();
	//Add Paste to the ApplicationManager
	virtual void Execute();
};