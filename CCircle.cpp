#include "CCircle.h"
#include <fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}
void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRCLE " << "  " << ID++ << "  " << Center.x << "  " << Center.y << "  " << Radius.x;
	OutFile << "  " << Radius.y;
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