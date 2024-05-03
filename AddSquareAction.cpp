#include "AddSquareAction.h"
#include "CSquare.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
	{
		pOut->PrintMessage("New Center: Click to decide Radius");

		//Read Radius and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);

		SquareGfxInfo.isFilled = false;	//default is not filled
		//get drawing, filling colors and pen width from the interface
		SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
		SquareGfxInfo.FillClr = pOut->getCrntFillColor();
	}

	pOut->ClearStatusBar();
}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Squar with the parameters read from the user
	CSquare* R = new CSquare(P1, P2, SquareGfxInfo);

	//Add the Square to the list of figures
	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
		pManager->AddFigure(R);
}