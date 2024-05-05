#pragma once
#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Figures\CFigure.h"
#include <cmath> 

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
	int CirID; //omar
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual bool isPointinside(int x, int y);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut) const;
};

#endif