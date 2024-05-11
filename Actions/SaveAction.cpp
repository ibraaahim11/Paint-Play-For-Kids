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
	FileName = pIn->GetSrting(pOut); //get file name from user
	pOut->ClearStatusBar();
}
void SaveAction::Execute()
{

	ReadActionParameters();
;

	ofstream OpenFile(FileName, ios::out);
	OpenFile << "BLUE" << "   " << "NO_COLOR" << endl << pManager->GetFigCount() << endl; 

	pManager->SaveAll(OpenFile); //calls save option for all figures
	OpenFile.close(); //close the opened file
}