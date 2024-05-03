#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;
	// test 1
	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	} while(ActType != EXIT);
	

	
	return 0;
}

