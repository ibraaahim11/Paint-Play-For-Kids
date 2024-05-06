#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"

CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{
	CountOfSelectedFig = 0;
}

void CopyAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	CFigure* SelectedFig;

	for (int i = 0; i < pManager->GetFigCount(); i++)   //get amount of selected figure count and the selected fig
	{
		if (pManager->GetFigure_index(i)->IsSelected())
		{
			CountOfSelectedFig++;
			SelectedFig = pManager->GetFigure_index(i);
		}
	}

	switch (CountOfSelectedFig) //anything but 1 selected figure will display error
	{

	case 1:
		Cptr = SelectedFig;
		pOut->PrintMessage("Figure Copied!");
		break;

	case 0:
		Cptr = NULL;
		pOut->PrintMessage("You Did Not Select a Figure!, Select one");
		break;
	default:
		Cptr = NULL;
		pOut->PrintMessage("Select Only One Figure!");
		break;
	}
}

void CopyAction::Execute()
{
	ReadActionParameters();
	if (!(Cptr == NULL)) {
		
		FigGfxInfo.DrawClr = Cptr->GetCrntDrawClr();      //getting GfxInfo Before making changes to them
		FigGfxInfo.isFilled = Cptr->GetGfxInfo().isFilled;
		FigGfxInfo.BorderWdth = Cptr->GetGfxInfo().BorderWdth;
		
		if(FigGfxInfo.isFilled)
			 FigGfxInfo.FillClr = Cptr->GetGfxInfo().FillClr;
		
		Cptr->SetGfxInfo(FigGfxInfo);  //setting the GfxInfo of the figure to be copied before any changes

		pManager->SetClipboard(Cptr); //adding figure to clipboard
	}
}