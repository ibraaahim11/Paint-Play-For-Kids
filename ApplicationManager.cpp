#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"
#include "AddHexagonAction.h"
#include "AddCircleAction.h"
#include "SelectAction.h"
#include "ClearAllAction.h"
#include "DeleteAction.h"
#include "BorderAction.h"
#include "FillAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\CopyAction.h"
#include <fstream>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedCount = 0;

	//Create an array of figure pointers and set them to NULL
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	SelectedFig = NULL;
	Clipboard = NULL;
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

	case SELECT:
		pAct = new SelectAction(this);
		break;
	case BORDER:
		pAct = new BorderAction(this);
		break;
	case FILL:
		pAct = new FillAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);

		break;
	case LOAD:
		pAct = new LoadAction(this);

		break;
	case CLEAR:
		pAct = new ClearAllAction(this);
		break;
	case I_DELETE:
		pAct = new DeleteAction(this);
		break;

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
void ApplicationManager::SaveAll(ofstream& OpenFile) //omar
{
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
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->isPointinside(x, y))
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

CFigure*& ApplicationManager::GetFigure_index(int index)
{
	//Return pointer to figure using its index in the figlist
	return FigList[index];
}
int ApplicationManager::GetFigCount() const
{
	// Return figure count
	return FigCount;
}
void ApplicationManager::SetFigCount(int num)
{
	// Sets figure count
	FigCount = num;
}
CFigure*& ApplicationManager::GetSelectedFig()
{
	// Returns currently selected figure by reference
	return SelectedFig;
}
void ApplicationManager::SetSelectedFig(CFigure* c)
{
	// Sets the currently selected figure
	SelectedFig = c;
}
CFigure*& ApplicationManager::GetClipboard()
{
	return Clipboard;
}
int ApplicationManager::CalculateSelectedCount()
{
	// Calculates and returns the number of selected figures
	SelectedCount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			SelectedCount++;
	}
	return SelectedCount;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)

		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)

	// Drawing bars again to avoid shapes from overlapping.
	pOut->CreateDrawToolBar();
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