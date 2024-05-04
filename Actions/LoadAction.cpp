#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
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
	int ID;
	ifstream InFile(FileName);
	if (InFile.is_open())
	{
		InFile >> CrntDrawClr >> CrntFillClr >> Count >> FigType;
		if (FigType == "R1")
		{
			CRectangle* R = new CRectangle(p1, p2, FigGfxInfo);
			R->Load(InFile);
			pManager->AddFigure(R);
		}
	}
	else
		pOut->PrintMessage("ERROR! File not found");

	string input;
}