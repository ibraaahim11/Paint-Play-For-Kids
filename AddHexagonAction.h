#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H

#include "Actions/Action.h"

//Add Hexagon Action class
class AddHexagonAction : public Action
{
private:
	Point P1, P2; //Hexagon center and radius
	GfxInfo HexagonGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hecagon to the ApplicationManager
	virtual void Execute();
};

#endif#pragma once
