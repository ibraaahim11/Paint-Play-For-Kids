#include "Switchtodraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Switchtodraw::Switchtodraw(ApplicationManager* pApp) : Action(pApp) {

}
void Switchtodraw::Execute() {
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
}
void Switchtodraw::ReadActionParameters() {

}
//return graph
