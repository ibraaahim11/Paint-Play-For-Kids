#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\CTriangle.h"
#include "..\CCircle.h"
#include "..\CHexagon.h"
#include "..\CSquare.h"

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
		
		Type = Cptr->GetType();

		switch (Type) //See which figure i will copy
		{
		case 'R':
		{
			Point p1, p2;
			p1 = ((CRectangle*)Cptr)->GetCorner1();
			p2 = ((CRectangle*)Cptr)->GetCorner2();
			CRectangle* R = new CRectangle(p1, p2, FigGfxInfo);  //making a copy of the selected figure
			CFigure* CFptr = R;
			pManager->SetClipboard(CFptr); //adding figure to clipboard
			break;
		}
		case 'T':
		{
			Point p1, p2, p3;
			p1 = ((CTriangle*)Cptr)->GetVertix1();
			p2 = ((CTriangle*)Cptr)->GetVertix2();
			p3 = ((CTriangle*)Cptr)->GetVertix3();
			CTriangle* T = new CTriangle(p1, p2, p3, FigGfxInfo);
			CFigure* CFptr = T;
			pManager->SetClipboard(CFptr); //adding figure to clipboard
			break;
		}
		case 'C':
		{
			Point p1, p2;
			p1 = ((CCircle*)Cptr)->GetCenter();
			p2 = ((CCircle*)Cptr)->GetRadius();
			CCircle* C = new CCircle(p1, p2, FigGfxInfo);
			CFigure* CFptr = C;
			pManager->SetClipboard(CFptr); //adding figure to clipboard
			break;
		}
		case 'H':
		{
			Point p1, p2;
			p1 = ((CHexagon*)Cptr)->GetCenter();
			p2 = ((CHexagon*)Cptr)->GetRadius();
			CHexagon* H = new CHexagon(p1, p2, FigGfxInfo);
			CFigure* CFptr = H;
			pManager->SetClipboard(CFptr); //adding figure to clipboard
			break;
		}
		case 'S':
		{
			Point p1, p2;
			p1 = ((CSquare*)Cptr)->GetCenter();
			p2 = ((CSquare*)Cptr)->GetRadius();
			CSquare* S = new CSquare(p1, p2, FigGfxInfo);
			CFigure* CFptr = S;
			pManager->SetClipboard(CFptr); //adding figure to clipboard
			break;
		}
		}

	}
}