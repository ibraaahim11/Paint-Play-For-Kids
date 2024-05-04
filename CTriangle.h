#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "Figures\CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertix1;
	Point Vertix2;
	Point Vertix3;
	int TriID;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual bool isPointinside(int x, int y);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
};

#endif