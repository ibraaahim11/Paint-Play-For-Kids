#include "DeleteAction.h"


#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedCount = 0;
}

void DeleteAction::ReadActionParameters()
{
}

//Execute the action
void DeleteAction::Execute()
{
	// Loop through figure list to delete selected figures.
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		// Get each figure by reference
		CFigure*& CurrentFig = pManager->GetFigure_index(i);
		// If it is selected we delete its contents and have the pointer point at null.
		if (CurrentFig->IsSelected())
		{
			delete CurrentFig;
			CurrentFig = NULL;
			SelectedCount++;

		}

	}

	// Fix order of the figure list.
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure*& CurrentFig = pManager->GetFigure_index(i);
		// If a pointer is empty go through the figures after it.
		if (CurrentFig == NULL)
		{
			for (int j = i + 1; j < pManager->GetFigCount(); j++)
			{
				// If a figure is found, the empty pointer points at it, and the other pointer points at null. (Organizing list)
				CFigure*& CurrentFig2 = pManager->GetFigure_index(j);
				if (CurrentFig2 != NULL)
				{
					CurrentFig = CurrentFig2;
					CurrentFig->SetID(i + 1);
					CurrentFig2 = NULL;
					// No need to go through the rest of the list. (Empty pointer now points at a figure)
					break;
				}
			}
		}
		else {
			
		}
	}
	Output* pOut = pManager->GetOutput();

	// Clear the previous draw area.
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	// Change figure count for the now smaller list.
	pManager->SetFigCount(pManager->GetFigCount() - SelectedCount);
	// Total number of figures has also changed.
	CFigure::SetTotalNum(pManager->GetFigCount());
	// No selected figures at this moment
	pManager->GetSelectedFig() = NULL;

	// Print a message if a figure has been deleted
	if (SelectedCount != 0)
		pOut->PrintMessage("Selected Figure(s) have been deleted.");

}