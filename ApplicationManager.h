#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "SoundAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int SelectedCount;

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure
	bool SoundOn; // boolean if sound is on

	ActionType ActType; // Action currently being performed 

	//	NOTE: This line must always be in the end of the "private" section
	SoundAction sound; // sound object used to play sounds throughout program's lifetime (composition)
public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const; 
	bool GetSoundOn() const; // returns if sound is on
	void SetSoundOn(bool); // sets sound on value
	void ExecuteAction(ActionType); //Creates an action and executes it
	void SaveAll(ofstream& OpenFile); //calls save function for all figures
	ActionType GetActType() const; // returns the type of action currently being performed

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure*& GetFigure_index(int index); //Search for a figure using its index
	void SetSelectedFig(CFigure* c);	// Sets the selected figure
	CFigure*& GetSelectedFig();	// Gets selected fig
	CFigure*& GetClipboard();	// Gets clipboard
	void SetClipboard(CFigure*& CF); //Sets the Clipboard

	int CalculateSelectedCount(); // returns number of figures currently selected
	int	GetFigCount() const; // Return figure count
	void SetFigCount(int); // Sets figure count

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
};

#endif