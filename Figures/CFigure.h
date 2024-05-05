#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <math.h>


//Base class for all figures
class CFigure
{
protected:
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int ID;		//Each figure has an ID

	const char Type; // Each figure has a char Type which represents which figure it is
	// R, S, C, T, H.

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo, char T);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	char GetType() const;

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure


	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function
	virtual bool isPointinside(int x, int y) = 0;
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif