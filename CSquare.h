#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H

#include "Figures\CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	Point Radius;

	// Corners of the square (useful for isPointinside function)
	Point Corner1;
	Point Corner2;


	int SquareID;
public:
	CSquare(Point, Point, GfxInfo FigureGfxInfo);
	virtual bool isPointinside(int x, int y);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);

};

#endif