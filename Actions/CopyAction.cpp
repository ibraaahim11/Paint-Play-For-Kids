//#include "CopyAction.h"
//#include "..\ApplicationManager.h"
//#include "..\GUI\input.h"
//#include "..\GUI\Output.h"
//
//
//CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
//{
//	CountOfSelectedFig = 0;
//}
//
//void CopyAction::ReadActionParameters()
//{
//
//	Output* pOut = pManager->GetOutput();
//	CFigure* SelectedFig;
//
//	for (int i = 0; i < pManager->GetFigCount(); i++)
//	{
//		if (pManager->GetFigure(i)->IsSelected())
//		{
//			CountOfSelectedFig++;
//			SelectedFig = pManager->GetFigure(i);
//		}
//	}
//
//	switch (CountOfSelectedFig)
//	{
//
//	case 1:
//		Cptr = SelectedFig;
//		pOut->PrintMessage("Figure Copied!");
//		break;
//
//	case 0:
//		Cptr = NULL;
//		pOut->PrintMessage("You Did Not Select a Figure!, Select one");
//		break;
//	default:
//		Cptr = NULL;
//		pOut->PrintMessage("Select Only One Figure!");
//		break;
//	}
//}
//
//void CopyAction::Execute()
//{
//	ReadActionParameters();
//	if (!(Cptr == NULL))
//		pManager->SetClipboard(Cptr);
//		
//}