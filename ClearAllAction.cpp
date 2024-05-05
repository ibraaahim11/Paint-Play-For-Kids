#include "ClearAllAction.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}

void ClearAllAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
}

//Execute the action
void ClearAllAction::Execute()
{
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		delete pManager->GetFigure_index(i);
		pManager->GetFigure_index(i) = NULL;
	}
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->SetFigCount(0);

	pManager->GetClipboard() = NULL;

	pManager->GetSelectedFig() = NULL;
	CFigure::SetTotalNum(0);
}