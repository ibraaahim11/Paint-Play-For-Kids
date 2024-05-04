#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"
#include "AddHexagonAction.h"
#include "AddCircleAction.h"
#include "Actions\SaveAction.h"
#include <fstream>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	//Create an array of selected figure pointers and set them to NULL
	for (int i = 0; i < MaxFigCount; i++)
		SelectedFigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQR:
		pAct = new AddSquareAction(this);

		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);

		break;

	case DRAW_HEX:
		pAct = new AddHexagonAction(this);

		break;
	case DRAW_CIR:
		pAct = new AddCircleAction(this);

		break;
	case SAVE:
		pAct = new SaveAction(this);

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
void ApplicationManager::SaveAll(string FileName) //omar
{
	color DrawClr, FillClr;

	DrawClr = pOut->getCrntDrawColor();
	FillClr = pOut->getCrntFillColor();

	string DrawColor, FillColor;

	if (DrawClr == BLACK)
		DrawColor = "BLACK";
	if (DrawClr == YELLOW)
		DrawColor = "YELLOW";
	if (DrawClr == RED)
		DrawColor = "RED";
	if (DrawClr == ORANGE)
		DrawColor = "ORANGE";
	if (DrawClr == GREEN)
		DrawColor = "GREEN";
	if (DrawClr == BLUE)
		DrawColor = "BLUE";


	if (FillClr == BLACK)
		FillColor = "BLACK";

	else if (FillClr == YELLOW)
		FillColor = "YELLOW";

	else if (FillClr == RED)
		FillColor = "RED";

	else if (FillClr == ORANGE)
		FillColor = "ORANGE";

	else if (FillClr == GREEN)
		FillColor = "GREEN";

	else if (FillClr == BLUE)
		FillColor = "BLUE";
	else
		FillColor = "NO_COLOR";


	ofstream OpenFile(FileName);
	OpenFile << DrawColor << "   " << FillColor << endl << FigCount << endl;


	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OpenFile);
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	//Add your code here to search for a figure given a point x,y
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}