#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{ }
void SaveAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Save Drawing, Type the Name of The File and add .txt at the end: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	color DrawClr, FillClr;

	DrawClr = pOut->getCrntDrawColor();
	FillClr = pOut->getCrntFillColor();
	
	string DrawColor, FillColor;

	if (DrawClr == BLACK)
		DrawColor = "BLACK";
	if (DrawClr == YELLOW)
		DrawColor = "YELLOW";
	if (DrawClr == RED)
		DrawColor = "RED";
	if (DrawClr == ORANGE)
		DrawColor = "ORANGE";
	if (DrawClr == GREEN)
		DrawColor = "GREEN";
	if (DrawClr == BLUE)
		DrawColor = "BLUE";


	if (FillClr == BLACK)
		FillColor = "BLACK";

	else if (FillClr == YELLOW)
		FillColor = "YELLOW";

	else if (FillClr == RED)
		FillColor = "RED";

	else if (FillClr == ORANGE)
		FillColor = "ORANGE";

	else if (FillClr == GREEN)
		FillColor = "GREEN";

	else if (FillClr == BLUE)
		FillColor = "BLUE";
	else
		FillColor = "NO_COLOR";


	ofstream OpenFile(FileName, ios::out);
	OpenFile << DrawColor << "   " << FillColor << endl << pManager->GetFigCount() << endl;


	pManager->SaveAll(OpenFile);
	OpenFile.close();
}