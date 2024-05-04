#pragma once
#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "Figures\CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	Point Radius;
	int HexID;
public:
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

};

#endif