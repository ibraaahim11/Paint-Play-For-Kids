#include "Pick&hide.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\ApplicationManager.h"
#include "..\DeleteAction.h"
#include "..\SelectAction.h"
#include "..\Figures\CFigure.h"
#include "Action.h"
#include <ctime>
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

	switch (Mode) {
	case FIG_TYPE: {

		int figuretype_size = 0;
		for (int i = 0; i < pManager->GetFigCount(); i++) {

			bool present = false;

			char type = pManager->GetFigure_index(i)->GetType();

			for (int j = 0; j < 5; j++)
			{
				if (figuretype[j] == type)
				{
					present = true;
					break;
				}
			}
			if (!present)
			{
				figuretype[figuretype_size++] = type;
			}


		}
		char randomshape;
		srand(time(NULL));
		do
		{
			randomshape = figuretype[rand() % pManager->GetFigCount()];
		} while (randomshape == 'Í');

		for (int i = 0; i < pManager->GetFigCount(); i++) {
		


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
					delete pAct;
					count++;
					pManager->UpdateInterface();
				}
				else
					pOut->PrintMessage("Wrong!");
			}
		}
		string c = "Number of correct choices: ";
		string m = c + std::to_string(count);
		pOut->PrintMessage(m);
		break;
	}

	case FIG_COLOR: {
		for (int i = 0; i < pManager->GetFigCount(); i++) {
			srand(time(NULL));
			string randomcolor = figurecolor[rand() % 6];

			string a = "pick all ";
			string b = a + randomcolor;
			pOut->PrintMessage(b);

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);

			ClickedFig= pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig->GetFillColor() == randomcolor) {
				ClickedFig->SetSelected(true);
				pAct = new DeleteAction(pManager);
				pAct->Execute();
				delete pAct;
				count++;
			}
			else
				pOut->PrintMessage("Wrong!");
		}

		string c = "Number of correct choices: ";
		string m = c + std::to_string(count);
		pOut->PrintMessage(m);
		break;

	}
	case BOTH:{
		for (int i = 0; i < pManager->GetFigCount(); i++) {
			srand(time(NULL));
			string randomcolor = figurecolor[rand() % 6];

			srand(time(NULL));
			char randomshape = figuretype[rand() % pManager->GetFigCount()];

			string a = "Pick all";
			string b = a + randomcolor + randomshape;
			pOut->PrintMessage(b);

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);

			ClickedFig = pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig->GetFillColor() == randomcolor && ClickedFig->GetType() == randomshape) {
				ClickedFig->SetSelected(true);

				pAct =new DeleteAction(pManager);
				pAct->Execute();
				delete pAct;
				count++;
			}
			else
				pOut->PrintMessage("Wrong!");
		}
		string c = "Number of correct choices: ";
		string m = c + std::to_string(count);
		pOut->PrintMessage(m);
		break;
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
