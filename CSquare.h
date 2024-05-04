#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H

#include "Figures\CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	Point Radius;
	int SquareID;
public:
	CSquare(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif