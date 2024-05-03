#pragma once
#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "Figures\CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif