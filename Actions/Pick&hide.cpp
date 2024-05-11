#include "Pick&hide.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\ApplicationManager.h"
#include "..\DeleteAction.h"
#include "..\SelectAction.h"
#include "..\Figures\CFigure.h"
#include "Action.h"
#include <ctime>
#include <fstream>
Pickandhide::Pickandhide(ApplicationManager* pApp) : Action(pApp) {}

void Pickandhide::Execute() 
{
	Point P1;
	Output* pOut = pManager->GetOutput();
	CFigure* ClickedFig;
	Action* pAct = NULL;
	DeleteAction* pApp;
	Switchtoplay STP(pManager);
	STP.Execute();


	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		CFigure* cfig = pManager->GetFigure_index(i);
		cfig->SetSelected(false);
		cfig->ChngDrawClr(cfig->GetCrntDrawClr());
		pManager->UpdateInterface();

	}


	ReadActionParameters();

	switch (Mode)
	{
	case FIG_TYPE: {
		

		// making figure type consist of only the figuress present
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
		// ensuring random shape is a char of a shape present
		// random shape is decided before user begins clicking



		int correct_guesses = 0;
		int incorrect_guesses = 0;

		do
		{
			randomshape = figuretype[rand() % pManager->GetFigCount()];
		} while (randomshape == 'Í');

		string shape = { randomshape };
		string a = "pick all ";
		string b = a + shape;
		pOut->PrintMessage(b);
		bool continue_game;
		do
		{


			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);

			ClickedFig = pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig != NULL) {
				if (ClickedFig->GetType() == randomshape) {
					ClickedFig->SetSelected(true);
					pAct = new DeleteAction(pManager);
					pAct->Execute();
					pOut->ClearStatusBar();
					pOut->PrintMessage(b);
					// delete afterwards
					delete pAct;
					correct_guesses++;
					// update interface to show changes
					pManager->UpdateInterface();
				}
				else
				{
					incorrect_guesses++;
				}

			}
			// if user wants to restart game
			continue_game = false;
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				if (pManager->GetFigure_index(i)->GetType() == randomshape)
					continue_game = true;
			}
		} while (continue_game);
		string msg = "Number of correct guesses: ";
		msg += std::to_string(correct_guesses);
		msg += " / Number of incorrect guesses: ";
		msg += std::to_string(incorrect_guesses);
		pOut->PrintMessage(msg);
		break;
	}

	case FIG_COLOR: {

		int figurecolor_size = 0;
		for (int i = 0; i < pManager->GetFigCount(); i++) {

			bool present = false;

			string color = pManager->GetFigure_index(i)->GetFillColor();

			for (int j = 0; j < 6; j++)
			{
				if (figurecolor[j] == color)
				{
					present = true;
					break;
				}
			}
			if (!present)
			{
				figurecolor[figurecolor_size++] = color;
			}


		}

		string randomcolor;
		srand(time(NULL));

		int correct_guesses = 0;
		int incorrect_guesses = 0;

		do
		{
			randomcolor = figurecolor[rand() % pManager->GetFigCount()];
		} while (randomcolor == "NO_COLOR" || randomcolor == "");

		string a = "pick all ";
		string b = a + randomcolor;
		pOut->PrintMessage(b);
		bool continue_game;
		do
		{


			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);

			ClickedFig = pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig != NULL) {
				if (ClickedFig->GetFillColor() == randomcolor) {
					ClickedFig->SetSelected(true);
					pAct = new DeleteAction(pManager);
					pAct->Execute();
					pOut->ClearStatusBar();
					pOut->PrintMessage(b);
					// delete afterwards
					delete pAct;
					correct_guesses++;
					// update interface to show changes
					pManager->UpdateInterface();
				}
				else
				{
					incorrect_guesses++;
				}

			}
			// if user wants to restart game
			continue_game = false;
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				if (pManager->GetFigure_index(i)->GetFillColor() == randomcolor)
					continue_game = true;
			}
		} while (continue_game);
		string msg = "Number of correct guesses: ";
		msg += std::to_string(correct_guesses);
		msg += " / Number of incorrect guesses: ";
		msg += std::to_string(incorrect_guesses);
		pOut->PrintMessage(msg);
		break;


	}
	case BOTH:
	{


		string randomcolor;
		srand(time(NULL));

		int correct_guesses = 0;
		int incorrect_guesses = 0;

		int random_index = rand() % pManager->GetFigCount();

		CFigure* RandomFigure = pManager->GetFigure_index(random_index);



		string random_color = RandomFigure->GetFillColor();
		char random_type = RandomFigure->GetType();
		string a = "pick all ";
		a += random_color;
		a += " ";
		a += random_type;

		pOut->PrintMessage(a);
		bool continue_game;
		do
		{

			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(P1.x, P1.y);

			ClickedFig = pManager->GetFigure(P1.x, P1.y);
			if (ClickedFig != NULL)
			{
				if (ClickedFig->GetFillColor() == random_color && ClickedFig->GetType() == random_type)
				{
					ClickedFig->SetSelected(true);
					pAct = new DeleteAction(pManager);
					pAct->Execute();
					pOut->ClearStatusBar();
					pOut->PrintMessage(a);
					// delete afterwards
					delete pAct;
					correct_guesses++;
					// update interface to show changes
					pManager->UpdateInterface();
				}
				else
				{
					incorrect_guesses++;
				}

			}
			// if user wants to restart game
			continue_game = false;
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				if (pManager->GetFigure_index(i)->GetFillColor() == random_color && pManager->GetFigure_index(i)->GetType() == random_type)
				{
					continue_game = true;
				}
			}
		} while (continue_game);
		string msg = "Number of correct guesses: ";
		msg += std::to_string(correct_guesses);
		msg += " / Number of incorrect guesses: ";
		msg += std::to_string(incorrect_guesses);
		pOut->PrintMessage(msg);
		break;
	}
	}
	}

	


	
	



void Pickandhide::ReadActionParameters() 
{
	Point P1;
	Output* pOut;
	pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose a mode");
	Input* pIn;
	pIn = pManager->GetInput();
	Mode = pIn->GetUserAction();
}
