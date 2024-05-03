#include "AddHexagonAction.h"
#include "CHexagon.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
	{
		pOut->PrintMessage("New Center: Click to decide Radius");

		//Read Radius and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);

		HexagonGfxInfo.isFilled = false;	//default is not filled
		//get drawing, filling colors and pen width from the interface
		HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
		HexagonGfxInfo.FillClr = pOut->getCrntFillColor();
	}

	pOut->ClearStatusBar();
}

//Execute the action
void AddHexagonAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Squar with the parameters read from the user
	CHexagon* R = new CHexagon(P1, P2, HexagonGfxInfo);

	//Add the Hexagon to the list of figures
	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
		pManager->AddFigure(R);
}