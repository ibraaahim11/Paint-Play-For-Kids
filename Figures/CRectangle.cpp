#include "CRectangle.h"
#include <fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::Save(ofstream& OutFile) // omar
{
	OutFile << "RECTANGLE " << "  " << ID++ << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y;
	string DrawColor, FillColor;
	if (FigGfxInfo.DrawClr == BLACK)
		DrawColor = "BLACK";
	if (FigGfxInfo.DrawClr == YELLOW)
		DrawColor = "YELLOW";
	if (FigGfxInfo.DrawClr == RED)
		DrawColor = "RED";
	if (FigGfxInfo.DrawClr == ORANGE)
		DrawColor = "ORANGE";
	if (FigGfxInfo.DrawClr == GREEN)
		DrawColor = "GREEN";
	if (FigGfxInfo.DrawClr == BLUE)
		DrawColor = "BLUE";


	if (FigGfxInfo.FillClr == BLACK)
		FillColor = "BLACK";

	else if (FigGfxInfo.FillClr == YELLOW)
		FillColor = "YELLOW";

	else if (FigGfxInfo.FillClr == RED)
		FillColor = "RED";

	else if (FigGfxInfo.FillClr == ORANGE)
		FillColor = "ORANGE";

	else if (FigGfxInfo.FillClr == GREEN)
		FillColor = "GREEN";

	else if (FigGfxInfo.FillClr == BLUE)
		FillColor = "BLUE";
	else
		FillColor = "NO_COLOR";

	OutFile << "  " << DrawColor << "  " << FillColor << endl;
}