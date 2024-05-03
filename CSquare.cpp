#include "CSquare.h"

CSquare::CSquare(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen
	pOut->DrawSquare(Center, Radius, FigGfxInfo, Selected);
}