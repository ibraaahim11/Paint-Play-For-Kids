#include "CHexagon.h"
#include <fstream>
CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
	HexID = ID;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a Hexagonon the screen
	pOut->DrawHex(Center, Radius, FigGfxInfo, Selected);
}
void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON " << "  " << HexID << "  " << Center.x << "  " << Center.y << "  " << Radius.x;
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


	if (!FigGfxInfo.isFilled)
		FillColor = "NO COLOR";
	else {
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
	}

	OutFile << "  " << DrawColor << "  " << FillColor << endl;
}