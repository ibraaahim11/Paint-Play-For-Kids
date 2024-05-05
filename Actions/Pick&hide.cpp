#include "Pick&hide.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\CTriangle.h"
#include "..\CCircle.h"
Pickandhide::Pickandhide(ApplicationManager* pApp) : Action(pApp) {
}
void Pickandhide::Generate() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Pick and hide game ");

	for (int i = 0; i < 5; i++) {
		int numWords = sizeof(figuretype) / sizeof(figuretype[0]);
		int randomIndex = rand() % numWords;
		string chosenshape = figuretype[randomIndex];
		pOut->PrintMessage("Pick all"); pOut->PrintMessage(chosenshape);

		if (chosenshape == "T") {
		
		}
		

	
	}
}