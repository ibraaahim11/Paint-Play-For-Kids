#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first Vertix");


	pIn->GetPointClicked(P1.x, P1.y);


	pOut->ClearStatusBar();
}

//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();



}