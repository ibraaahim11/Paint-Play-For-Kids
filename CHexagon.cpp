#include "CHexagon.h"

CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a Hexagonon the screen
	pOut->DrawHex(Center, Radius, FigGfxInfo, Selected);
}