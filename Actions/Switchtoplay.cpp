#include"Switchtoplay.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Switchtoplay::Switchtoplay(ApplicationManager* pApp) :Action(pApp) 
{
}
void Switchtoplay::Execute() {
	Output* pOut;
	pOut->ClearDrawArea();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
 void Switchtoplay:: ReadActionParameters(){
 }