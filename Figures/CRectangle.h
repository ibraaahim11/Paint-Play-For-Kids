#ifndef CRECT_H
#define CRECT_H
#include <fstream>
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
	int RectID;
	int Height;
	int Width;

public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual bool isPointinside(int x, int y);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile); //omar
	virtual void Load(ifstream& Infile);
	virtual Point GetCenter();
	virtual void PrintInfo(Output* pOut) const;
	Point GetCorner1();
	Point GetCorner2();
	int GetHeight(); // usefull for paste
	int GetWidth(); // usefull for paste
};

#endif