#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\CTriangle.h"
#include "..\CCircle.h"
#include "..\CSquare.h"
#include "..\CHexagon.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Drawing, Type the Name of The File and add .txt at the end: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	int Count;
	string CrntDrawClr, CrntFillClr, FigType, DrawClr, FillClr;

	ReadActionParameters();

	ifstream InFile(FileName);
	if (InFile.is_open())
	{
		InFile >> CrntDrawClr >> CrntFillClr >> Count;
		for (int i = 0; i < Count; i++)
		{
			InFile >> FigType;
			if (FigType == "R1")
			{
				CRectangle* R = new CRectangle(p1, p2, FigGfxInfo);
				R->Load(InFile);
				pManager->AddFigure(R);
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
	}
	else
		pOut->PrintMessage("ERROR! File not found");

	string input;
}