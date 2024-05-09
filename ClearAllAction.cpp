#include "ClearAllAction.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}

void ClearAllAction::ReadActionParameters()
{
}

//Execute the action
void ClearAllAction::Execute()
{
	// Go through the entire figure list. Delete its content and set all pointers to NULL.
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure*& CurrentFig = pManager->GetFigure_index(i);
		delete CurrentFig;
		CurrentFig = NULL;
	}
	// Clear Window and reset all values.
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->SetFigCount(0);

	pManager->GetClipboard() = NULL;

	pManager->GetSelectedFig() = NULL;
	CFigure::SetTotalNum(0);
}