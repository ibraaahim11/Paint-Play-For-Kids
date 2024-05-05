#include "Action.h"
#include "..\Figures\CFigure.h"

class LoadAction : public Action
{
protected:
	string FileName; //name of file to read from
	Point p1, p2, p3; // points of loaded figure
	GfxInfo FigGfxInfo; //GfxInfo of created figure
public:
	LoadAction(ApplicationManager* pApp); 
	virtual void ReadActionParameters();
	virtual void Execute();
};