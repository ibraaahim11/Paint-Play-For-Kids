#include "Pick&hide.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\ApplicationManager.h"
#include "..\CTriangle.h"
#include "..\CCircle.h"
#include "..\CSquare.h"
#include "..\CHexagon.h"
Pickandhide::Pickandhide(ApplicationManager* pApp) : Action(pApp) {}

void Pickandhide::Generate(PlayMenuItem(Playmenu)) {
	Point P1;
	Output* pOut = pManager->GetOutput();
	CFigure* ClickedFig;
	pOut->PrintMessage("Pick and hide game ");

	switch(Playmenu){
	case ITM_FIG_TYPE: {

		for (int i = 0; i < 5; i++) {
			int numWords = sizeof(figuretype) / sizeof(figuretype[0]);
			int randomIndex = rand() % numWords;
			string randomshape = figuretype[randomIndex];

			pOut->PrintMessage("Pick all"); pOut->PrintMessage(randomshape);

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);


			ClickedFig = pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig == randomshape)
				count = +1;
			break;
		}
	case ITM_FIG_COLOR: {
		for (int i = 0; i < 6; i++) {
			int numWords = sizeof(figurecolor) / sizeof(figurecolor[0]);
			int randomIndex = rand() % numWords;
			string randomcolor = figurecolor[randomIndex];

			pOut->PrintMessage("Pick all"); pOut->PrintMessage(randomcolor); pOut->PrintMessage("Shapes");

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);
			color CrntDrawClr;
			if (CrntDrawClr == randomcolor)
				count = +1;
		}
	}
	}
}