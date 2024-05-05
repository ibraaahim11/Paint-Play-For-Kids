#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <string>

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	// Initialize all shapes (num of shapes selected read every time SelectAction is clicked)
	Num_RectangleSelected = 0; Num_SquareSelected = 0; Num_TriangleSelected = 0;
	Num_CircleSelected = 0; Num_HexagonSelected = 0;
}

void SelectAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	//Read Point and store it in P1
	pIn->GetPointClicked(P1.x, P1.y);

	ClickedFig = pManager->GetFigure(P1.x, P1.y);

	if (ClickedFig != NULL)
	{
		// If the point is found inside a figure we switch its "Selection status"

		ClickedFig->SetSelected(!(ClickedFig->IsSelected()));

		// If the clicked figure was "unselected" we assume there is currently no selected figure.

		if (!(ClickedFig->IsSelected()))
			pManager->SetSelectedFig(NULL);

		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			// We take each figure in the figure list
			CFigure* CurrentFig = pManager->GetFigure_index(i);

			// If only one figure is selected it becomes the "SelectedFig" in Application Manager
			// If more than one figure is selected, the "SelectedFig" in Application Manager is not important
			// and is assigned the last selected fig in fig list.
			if (CurrentFig->IsSelected())
			{
				pManager->SetSelectedFig(CurrentFig);
				// We increment the number of selected figs based on each type.
				char Type = CurrentFig->GetType();
				switch (Type)
				{
				case 'R': Num_RectangleSelected++; break;
				case 'S': Num_SquareSelected++; break;
				case 'T': Num_TriangleSelected++; break;
				case 'C': Num_CircleSelected++; break;
				case 'H': Num_HexagonSelected++; break;
				}
			}
		}
	}
	else
	{
		pManager->SetSelectedFig(NULL); // If user click was not inside any shape, there will be no selected figures.
	}
}

//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (ClickedFig != NULL)
	{
		// If clicked figure was selected it should be highlighted. Else, revert to original color.
		if (ClickedFig->IsSelected())
		{
			ClickedFig->ChngDrawClr(MAGENTA);
		}
		else
		{
			ClickedFig->ChngDrawClr(BLUE);
		}
	}
	else
	{
		// User click not inside any shape. Deselect all figures. Revert all figure colors.
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			(pManager->GetFigure_index(i))->SetSelected(false);
			(pManager->GetFigure_index(i))->ChngDrawClr(BLUE);
		}
	}

	int Num_TotalSelected = Num_RectangleSelected + Num_SquareSelected + Num_TriangleSelected + Num_CircleSelected + Num_HexagonSelected;

	// No fig clicked -> no msg displayed
	if (Num_TotalSelected == 0)
	{
		pOut->ClearStatusBar();
	}

	// One figure clicked and selected -> print its info.
	else if (Num_TotalSelected == 1)
	{
		pManager->GetSelectedFig()->PrintInfo(pOut);
	}

	// More than one figure clicked -> Display number of each shape clickd
	else
	{
		string msg = "Selected: ";

		if (Num_RectangleSelected > 0)
		{	// Convert int to string and add it to the msg that will be printed
			auto s_num = std::to_string(Num_RectangleSelected);
			msg += (s_num + " Rectangle(s). ");
		}
		if (Num_SquareSelected > 0)
		{
			auto s_num = std::to_string(Num_SquareSelected);
			msg += (s_num + " Square(s). ");
		}
		if (Num_TriangleSelected > 0)
		{
			auto s_num = std::to_string(Num_TriangleSelected);
			msg += (s_num + " Triangle(s). ");
		}
		if (Num_CircleSelected > 0)
		{
			auto s_num = std::to_string(Num_CircleSelected);
			msg += (s_num + " Circle(s). ");
		}
		if (Num_HexagonSelected > 0)
		{
			auto s_num = std::to_string(Num_HexagonSelected);
			msg += (s_num + " Hexagon(s). ");
		}
		pOut->PrintMessage(msg);
	}
}