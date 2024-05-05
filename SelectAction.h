#pragma once
#ifndef SELECT_H
#define SELECT_H
#include "Actions/Action.h"
#include "Figures\CFigure.h"

class SelectAction : public Action
{
private:
	Point P1; //Point clicked
	CFigure* SelectedFig;

	// number of each shape currently selected
	int Num_RectangleSelected;
	int Num_SquareSelected;
	int Num_TriangleSelected;
	int Num_CircleSelected;
	int Num_HexagonSelected;



public:
	SelectAction(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute();
};

#endif