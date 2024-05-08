#include "Pick&hide.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\ApplicationManager.h"
#include "..\DeleteAction.h"
#include "..\SelectAction.h"
#include "..\Figures\CFigure.h"
#include "Action.h"
Pickandhide::Pickandhide(ApplicationManager* pApp) : Action(pApp) {}

void Pickandhide::Execute() {
	Point P1;
	Output* pOut = pManager->GetOutput();
	CFigure* ClickedFig;
	Action* pAct = NULL;
	DeleteAction* pApp;
	Switchtoplay STP(pManager);
	STP.Execute();


	ReadActionParameters();

	switch (Mode)
	case FIG_TYPE: {

		for (int i = 0; i < pManager->GetFigCount(); i++) {
			int numWords = sizeof(figuretype) / sizeof(figuretype[0]);
			int randomIndex = rand() % numWords;
			char randomshape = figuretype[randomIndex];
			string shape = { randomshape };
			string a = "pick all ";
			string b = a + shape;
			pOut->PrintMessage(b);

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);


			ClickedFig = pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig != NULL) {
				if (ClickedFig->GetType() == randomshape) {
					ClickedFig->SetSelected(true);
					pAct = new DeleteAction(pManager);
					pAct->Execute();
					count = +1;

				}
				else
					pOut->PrintMessage("Wrong!");
			}
			
			

		}
		break;

	case FIG_COLOR: {
		for (int i = 0; i < 6; i++) {
			int numWords = sizeof(figurecolor) / sizeof(figurecolor[0]);
			int randomIndex = rand() % numWords;
			string randomcolor = figurecolor[randomIndex];

			pOut->PrintMessage("Pick all"); pOut->PrintMessage(randomcolor); pOut->PrintMessage("Shapes");

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);
			color CrntDrawClr;
	
			if (ClickedFig->GetFillColor() == randomcolor) {
				ClickedFig->SetSelected(true);
				pAct = new DeleteAction(pManager);
				pAct->Execute();
				count = +1;
			}
		}
		
		//pOut->PrintMessage(count)
	}
	}
	}
void Pickandhide::ReadActionParameters() {
	Point P1;
	Output* pOut;
	pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose a mode");
	Input* pIn;
	pIn = pManager->GetInput();
	Mode = pIn->GetUserAction();
}
