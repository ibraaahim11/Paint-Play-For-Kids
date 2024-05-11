#include"Switchtoplay.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Switchtoplay::Switchtoplay(ApplicationManager* pApp) :Action(pApp) 
{
}
void Switchtoplay::Execute() {
	Output* pOut = pManager->GetOutput();
	Action* pAct = NULL;
	pAct = new SaveAction(pManager);
	pAct->Execute();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
 void Switchtoplay:: ReadActionParameters(){
 }