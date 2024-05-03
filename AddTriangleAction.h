#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Actions/Action.h"

//Add Triangle Action class
class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; //Vertices of Triangle
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();
};

#endif