#include "AddCircleAction.h"
#include "CCircle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
	{
		pOut->PrintMessage("New Center: Click to decide Radius");

		//Read Radius and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);

		CircleGfxInfo.isFilled = false;	//default is not filled
		//get drawing, filling colors and pen width from the interface
		CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
		CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	}

	pOut->ClearStatusBar();
}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Squar with the parameters read from the user
	CCircle* R = new CCircle(P1, P2, CircleGfxInfo);

	//Add the Circle to the list of figures
	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
		pManager->AddFigure(R);
}