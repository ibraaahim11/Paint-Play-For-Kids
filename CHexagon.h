#pragma once
#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "Figures\CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	Point Radius;

	int Vertices_x[6];
	int Vertices_y[6];

	static int SelectedNum;

public:
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	void Calculate_Vertices();
	virtual bool isPointinside(int x, int y);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
};

#endif