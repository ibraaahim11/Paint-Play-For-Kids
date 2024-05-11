#include"Switchtoplay.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include <fstream>
Switchtoplay::Switchtoplay(ApplicationManager* pApp) :Action(pApp) 
{
}
void Switchtoplay::AutomaticSave()
{
	ofstream OpenFile("TTEEEESTTT3258.txt", ios::out);
	OpenFile << "BLUE" << "   " << "NO_COLOR" << endl << pManager->GetFigCount() << endl;

	pManager->SaveAll(OpenFile); //calls save option for all figures
	OpenFile.close(); //close the opened file
}

void Switchtoplay::Execute() {
	Output* pOut = pManager->GetOutput();
	AutomaticSave();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
 void Switchtoplay:: ReadActionParameters(){
 }