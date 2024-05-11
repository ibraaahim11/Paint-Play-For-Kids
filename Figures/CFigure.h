#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <math.h>
#include <string>

//Base class for all figures
class CFigure
{
protected:
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int TotalNum;		// Total number of figures
	int ID; // Each figure has an ID

	color CrntDrawClr; // Border Color of the figure before being selected (selected = Magenta)
	const char Type; // Each figure has a char Type which represents which figure it is
	// R, S, C, T, H.
	string DrawColor, FillColor; // colors of figures in strings for info printing, reading and writing to files
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo, char T);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	char GetType() const;		// REsturns type of figure in char form
	void SetID(int id);

	void SetGfxInfo(GfxInfo FigGfxInfo);
	GfxInfo GetGfxInfo() const;
	string GetFillColor()const; //Return fill color

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void UpdateFillClrString(); // Updates the DrawColor string in case it has changed
	void UpdateDrwClrString();	// Updates the DrawColor string in case it has changed
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color GetCrntDrawClr() const;  // Returns the draw color of the figure (Not magenta which is due to select action)

	void SetCrntDrawClr(color); // Sets current draw color (Not magenta which is due to select action)
	static void SetTotalNum(int num); // Sets totla num of figures

	virtual void PrintInfo(Output* pOut) const = 0; // Virtual function to print information of figure.

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function
	virtual bool isPointinside(int x, int y) = 0;
	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	virtual Point GetCenter() = 0; // return center for each figure
	
};

#endif