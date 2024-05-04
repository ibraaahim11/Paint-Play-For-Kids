#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a Triangle on the screen
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}
void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE " << "  " << ID++ << "  " << Vertix1.x << "  " << Vertix1.y << "  " << Vertix2.x << "  ";
	OutFile << Vertix2.y << "  " << Vertix3.x << "  " << Vertix3.y;
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