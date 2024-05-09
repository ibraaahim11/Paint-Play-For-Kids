#include "Switchtodraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "LoadAction.h"

Switchtodraw::Switchtodraw(ApplicationManager* pApp) : Action(pApp) {

}
void Switchtodraw::Execute() {
	Output* pOut = pManager->GetOutput();
	Action* pAct;
	pAct = new LoadAction(pManager);
	pAct->Execute();
	pOut->CreateDrawToolBar();
	
}
void Switchtodraw::ReadActionParameters() {

}