#include "AddTriangleAction.h"
#include "CTriangle.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first Vertix");

	//Read first Vertix and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
	{
		pOut->PrintMessage("New Triangle: Click at second Vertix");

		//Read second Vertix and store in point P1
		pIn->GetPointClicked(P2.x, P2.y);

		pOut->PrintMessage("New Triangle: Click at third Vertix");

		//Read third Vertix and store in point P1
		pIn->GetPointClicked(P3.x, P3.y);

		TriangleGfxInfo.isFilled = false;	//default is not filled
		//get drawing, filling colors and pen width from the interface
		TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
		TriangleGfxInfo.FillClr = pOut->getCrntFillColor();
	}

	pOut->ClearStatusBar();
}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Squar with the parameters read from the user
	CTriangle* R = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Add the Triangle to the list of figures
	// Only if first click is in the drawing area. Else, user is canceling action.
	if (P1.y > 50 && P1.y < 600)
		pManager->AddFigure(R);
}