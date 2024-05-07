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
			if (FigType == "R")
			{
				Point p3, p4;
				CRectangle* R = new CRectangle(p1, p2, FigGfxInfo); //making a dummy Figure
				R->Load(InFile); //call save of the specific figure
				p3 = R->GetCorner1();
				p4 = R->GetCorner2(); //Getting the points from file 
				FigGfxInfo = R->GetGfxInfo();
				CRectangle* R1 = new CRectangle(p3, p4, FigGfxInfo); //calling the constructor correctly with correct parameters
				delete R; // deleting the dummy figure
				pManager->AddFigure(R1); //add the created figure to figure list
			}
			if (FigType == "T")
			{
				Point p6, p4, p5;
				CTriangle* T = new CTriangle(p1, p2, p3, FigGfxInfo);
				T->Load(InFile);
				p4 = T->GetVertix1();
				p5 = T->GetVertix2();
				p6 = T->GetVertix3();
				FigGfxInfo = T->GetGfxInfo();
				CTriangle* T1 = new CTriangle(p4, p5, p6, FigGfxInfo);
				delete T;
				pManager->AddFigure(T1);
			}
			if (FigType == "H")
			{
				Point p3, p4;
				CHexagon* H = new CHexagon(p1, p2, FigGfxInfo);
				H->Load(InFile);
				p3 = H->GetCenter();
				p4 = H->GetRadius();
				FigGfxInfo = H->GetGfxInfo();
				CHexagon* H1 = new CHexagon(p3, p4, FigGfxInfo);
				delete H;
				pManager->AddFigure(H1);

			}
			if (FigType == "S")
			{
				Point p3, p4;
				CSquare* S = new CSquare(p1, p2, FigGfxInfo);
				S->Load(InFile);
				p3 = S->GetCenter();
				p4 = S->GetRadius();
				FigGfxInfo = S->GetGfxInfo();
				CSquare* S1 = new CSquare(p3, p4, FigGfxInfo);
				delete S;
				pManager->AddFigure(S1);
			}
			if (FigType == "C")
			{
				Point p3, p4;
				CCircle* C = new CCircle(p1, p2, FigGfxInfo);
				C->Load(InFile);
				p3 = C->GetCenter();
				p4 = C->GetRadius();
				FigGfxInfo = C->GetGfxInfo();
				CCircle* C1 = new CCircle(p3, p4, FigGfxInfo);
				delete C;
				pManager->AddFigure(C1);
			}
		}
		InFile.close(); //close file

	}
	else
		pOut->PrintMessage("ERROR! File not found");
}