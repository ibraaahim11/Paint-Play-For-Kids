#pragma once
#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Figures\CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif