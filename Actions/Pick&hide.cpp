#include "Pick&hide.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

Pickandhide::Pickandhide(ApplicationManager* pApp) : Action(pApp) {
}
void Pickandhide::Generate() {
	Output* pOut;
	pOut->PrintMessage("Pick and hide game ");

	for (int i = 0; i < 5; i++) {
		int numWords = sizeof(figuretype) / sizeof(figuretype[0]);
		int randomIndex = rand() % numWords;
		string selectedWord = figuretype[randomIndex];
		pOut->PrintMessage("Pick all"); pOut->PrintMessage(selectedWord);
		

	
	}
}