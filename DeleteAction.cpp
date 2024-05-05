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

	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure* CurrentFig = pManager->GetFigure_index(i);
		if (CurrentFig->IsSelected())
		{
			delete CurrentFig;
			CurrentFig = NULL;
			SelectedCount++;
		}
	}

	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure* CurrentFig = pManager->GetFigure_index(i);
		if (CurrentFig == NULL)
		{
			for (int j = i + 1; j < pManager->GetFigCount(); j++)
			{
				CFigure* CurrentFig2 = pManager->GetFigure_index(j);
				if (CurrentFig2 != NULL)
				{
					CurrentFig = CurrentFig2;
					CurrentFig2 = NULL;
					break;
				}
			}
		}
	}
	Output* pOut = pManager->GetOutput();

	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->SetFigCount(pManager->GetFigCount() - SelectedCount);
	pManager->GetSelectedFig() = NULL;

	pOut->PrintMessage("Selected Figure(s) have been deleted.");
}