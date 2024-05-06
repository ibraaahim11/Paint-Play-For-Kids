#include "FillAction.h"

#include "ApplicationManager.h"

FillAction::FillAction(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void FillAction::ReadActionParameters()
{
	// Get number of selected figures.
	SelectedCount = pManager->CalculateSelectedCount();

	// Can only change one figure.
	if (SelectedCount == 1)
	{
		SelectedFig = pManager->GetSelectedFig();
		// Get the color chosen by user.
		pOut->PrintMessage("Pick a color!");

		const ActionType Color_Action = pIn->GetUserAction();
		switch (Color_Action)
		{
		case I_BLACK:
			Color = BLACK;
			break;
		case I_YELLOW:
			Color = YELLOW;
			break;
		case I_ORANGE:
			Color = ORANGE;
			break;
		case I_RED:
			Color = RED;
			break;
		case I_GREEN:
			Color = GREEN;
			break;
		case I_BLUE:
			Color = BLUE;
			break;
		}
	}
}

//Execute the action
void FillAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	// Only one figure fill color can be changed at a time..
	if (SelectedCount > 1)
		pOut->PrintMessage("Error: You can only change one figure's fill color at a time.");
	else if (SelectedCount == 1)
	{
		SelectedFig->ChngFillClr(Color);
		SelectedFig->PrintInfo(pOut);
	}
}