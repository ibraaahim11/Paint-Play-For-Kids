#pragma once
#ifndef SELECT_H
#define SELECT_H
#include "Actions/Action.h"
#include "Figures\CFigure.h"

class SelectAction : public Action
{
private:
	Point P1; //Point clicked
	CFigure* ClickedFig; //Figure Clicked on

	// Number of each shape currently selected
	int Num_RectangleSelected;
	int Num_SquareSelected;
	int Num_TriangleSelected;
	int Num_CircleSelected;
	int Num_HexagonSelected;

	Output* pOut; //Output pointer to print msgs
	Input* pIn; //Input pointer to read user clicks

public:
	SelectAction(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute();
};

#endif