#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\CTriangle.h"
#include "..\CCircle.h"
#include "..\CSquare.h"
#include "..\CHexagon.h"
#include "..\ClearAllAction.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
	p1.x = p1.y = 0;                                // initializing
	p2.x = p2.y = 100;                              // All
	p3.x = p3.y = 200;                              // Points
	FigGfxInfo.isFilled = false;
}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Drawing, Type the Name of The File and add .txt at the end: ");
	FileName = pIn->GetSrting(pOut); // Get File name from user
	pOut->ClearStatusBar();
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput(); // to display a message on status bar
	int Count; // count of current figures
	string CrntDrawClr, CrntFillClr, FigType, DrawClr, FillClr; //storing the colors as strings

	ReadActionParameters();
	ifstream InFile(FileName);
	if (InFile.is_open()) // check if file is on your desktop
	{
		pAct = new ClearAllAction(pManager);
		pAct->Execute(); //clear all figures
		InFile >> CrntDrawClr >> CrntFillClr >> Count; //reading first two lines from file
		for (int i = 0; i < Count; i++) //creating pointers to figures according to the figure type
		{
			InFile >> FigType; 
			if (FigType == "R1")
			{
				CRectangle* R = new CRectangle(p1, p2, FigGfxInfo);
				R->Load(InFile); //call save of the specific figure
				pManager->AddFigure(R); //add the created figure to figure list
			}
			if (FigType == "T1")
			{
				CTriangle* T = new CTriangle(p1, p2, p3, FigGfxInfo);
				T->Load(InFile);
				pManager->AddFigure(T);
			}
			if (FigType == "H1")
			{
				CHexagon* H = new CHexagon(p1, p2, FigGfxInfo);
				H->Load(InFile);
				pManager->AddFigure(H);
			}
			if (FigType == "S1")
			{
				CSquare* S = new CSquare(p1, p2, FigGfxInfo);
				S->Load(InFile);
				pManager->AddFigure(S);
			}
			if (FigType == "C1")
			{
				CCircle* C = new CCircle(p1, p2, FigGfxInfo);
				C->Load(InFile);
				pManager->AddFigure(C);
			}
		}
		InFile.close(); //close file
	}
	else
		pOut->PrintMessage("ERROR! File not found");

}