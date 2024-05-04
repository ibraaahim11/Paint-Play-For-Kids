#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
	TriID = ID;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a Triangle on the screen
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}
void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "T1" << " " << TriID << " " << Vertix1.x << " " << Vertix1.y << " " << Vertix2.x << " ";
	OutFile << Vertix2.y << " " << Vertix3.x << " " << Vertix3.y;
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
	OutFile << " " << DrawColor << " " << FillColor << endl;
}
void CTriangle::Load(ifstream& Infile)
{
	string FigureType, DrawColor, FillColor;
	Infile >> FigureType >> TriID >> Vertix1.x >> Vertix1.y >> Vertix2.x >> Vertix2.y
		>> Vertix3.x >> Vertix3.y >> DrawColor >> FillColor;
	
	if (DrawColor == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (DrawColor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (DrawColor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (DrawColor == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (DrawColor == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (DrawColor == "BLUE")
		FigGfxInfo.DrawClr = BLUE;

	if (FillColor == "NO COLOR")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;

		if (FillColor == "GREEN")
			FigGfxInfo.FillClr = GREEN;
		else if (FillColor == "BLACK")
			FigGfxInfo.FillClr = BLACK;
		else if (FillColor == "BLACK")
			FigGfxInfo.FillClr = BLACK;
		else if (FillColor == "RED")
			FigGfxInfo.FillClr = RED;
		else if (FillColor == "ORANGE")
			FigGfxInfo.FillClr = ORANGE;
		else if (FillColor == "BLUE")
			FigGfxInfo.FillClr = BLUE;
	}

}
