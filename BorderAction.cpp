#include "BorderAction.h"

#include "ApplicationManager.h"

BorderAction::BorderAction(ApplicationManager* pApp) :Action(pApp)
{
	// Pointers needed for user input and output
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void BorderAction::ReadActionParameters()
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
void BorderAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (SelectedCount > 1)
		pOut->PrintMessage("Error: You can only change one figure's border color at a time.");
	else if (SelectedCount == 1)
	{
		// Change color
		SelectedFig->ChngDrawClr(Color);
		// This border color is the current draw color. (Not magenta which is the color due to select action)
		SelectedFig->SetCrntDrawClr(Color);
		SelectedFig->PrintInfo(pOut);
	}
}