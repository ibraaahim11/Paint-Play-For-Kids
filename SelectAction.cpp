#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	Num_RectangleSelected = 0; Num_SquareSelected = 0; Num_TriangleSelected = 0;
	Num_CircleSelected = 0; Num_HexagonSelected = 0;
}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();



	//Read Point and store it in P1
	pIn->GetPointClicked(P1.x, P1.y);
	// If the point is found inside a figure we switch its "Selection status"
	SelectedFig = pManager->GetFigure(P1.x, P1.y);
	if(SelectedFig != NULL)
	{
		SelectedFig->SetSelected(!(SelectedFig->IsSelected()));
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			CFigure* CurrentFig = pManager->GetFigure(i);
			if (CurrentFig->IsSelected())
			{
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


}

//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if(SelectedFig != NULL)
	{

		if (SelectedFig->IsSelected())
		{

			SelectedFig->ChngDrawClr(MAGENTA);
		}
		else
		{
			SelectedFig->ChngDrawClr(BLUE);
		}
	}
	else
	{
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			(pManager->GetFigure(i))->SetSelected(false);
			(pManager->GetFigure(i))->ChngDrawClr(BLUE);
			Num_RectangleSelected = 0; Num_SquareSelected = 0; Num_TriangleSelected = 0;
			Num_CircleSelected = 0; Num_HexagonSelected = 0;
		}
	}
	int Num_TotalSelected = Num_RectangleSelected + Num_SquareSelected + Num_TriangleSelected +
		Num_CircleSelected + Num_HexagonSelected;

	if (Num_TotalSelected == 0){}
	else if (Num_TotalSelected == 1)
	{
		// bos hena el current selected ely hwoa private data member. hayba 3andak pure virtual function tenady 3aleha bet print info lel bt3 da
	}
	else
	{
		// hena ba a3mel eno kaza if law haga mesh 0
		// hat print “Selected: 1 Rectangle(s), 2 triangle(s), 1 Hexagon(s) “ 
		
		}
	
	




}