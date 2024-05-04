#include "Action.h"


class LoadAction : public Action
{
protected:
	string FileName;
	Point p1, p2;
	GfxInfo FigGfxInfo;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};