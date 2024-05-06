#include "Action.h"
#include "..\Figures\CFigure.h"

class CopyAction : public Action
{
	int CountOfSelectedFig; // if more than one displays error
	CFigure* Cptr;        //to get clipboard figure
	GfxInfo FigGfxInfo;  //GfxInfo of Fig before making changes to it
	char Type;
public:
	CopyAction(ApplicationManager* pApp);
	// Reads Copy Parameters
	virtual void ReadActionParameters();
	//Add Copy to the ApplicationManager
	virtual void Execute();


};