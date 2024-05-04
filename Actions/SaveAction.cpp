#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


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
	ReadActionParameters();
	pManager->SaveAll(FileName);

}