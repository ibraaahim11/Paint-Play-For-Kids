#include "CTriangle.h"
#include <fstream>

#include <iostream>
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'T')
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
	ID = TotalNum;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a Triangle on the screen
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output* pOut) const
{
	auto s_ID = std::to_string(ID);
	pOut->PrintMessage("Triangle Selected: ID " + s_ID);
}

bool CTriangle::isPointinside(int x, int y)
{
	// Using the Barycentric Coordinates

	// Calculating (u,v,w)

	double det = (Vertix2.y - Vertix3.y) * (Vertix1.x - Vertix3.x) + (Vertix3.x - Vertix2.x) * (Vertix1.y - Vertix3.y);
	double factor_u = (Vertix2.y - Vertix3.y) * (x - Vertix3.x) + (Vertix3.x - Vertix2.x) * (y - Vertix3.y);
	double factor_v = (Vertix3.y - Vertix1.y) * (x - Vertix3.x) + (Vertix1.x - Vertix3.x) * (y - Vertix3.y);
	double u = factor_u / det;
	double v = factor_v / det;
	double w = 1.0 - u - v;

	if (w >= 0 && w <= 1 && v >= 0 && v <= 1 && u >= 0 && u <= 1)
		return true;
	else
		return false;
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "T1" << " " << TriID << " " << Vertix1.x << " " << Vertix1.y << " " << Vertix2.x << " ";
	OutFile << Vertix2.y << " " << Vertix3.x << " " << Vertix3.y;

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
	
	if (FigGfxInfo.DrawClr == MAGENTA)
	{
		if (CrntDrawClr == BLACK)
			DrawColor = "BLACK";

		if (CrntDrawClr == YELLOW)
			DrawColor = "YELLOW";

		if (CrntDrawClr == RED)
			DrawColor = "RED";

		if (CrntDrawClr == ORANGE)
			DrawColor = "ORANGE";

		if (CrntDrawClr == GREEN)
			DrawColor = "GREEN";

		if (CrntDrawClr == BLUE)
			DrawColor = "BLUE";
	}
	if (!FigGfxInfo.isFilled)
		FillColor = "NO_COLOR";
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

	Infile >> TriID >> Vertix1.x >> Vertix1.y >> Vertix2.x >> Vertix2.y
		>> Vertix3.x >> Vertix3.y >> DrawColor >> FillColor;

	if (DrawColor == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (DrawColor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (DrawColor == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	else if (DrawColor == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (DrawColor == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (DrawColor == "BLUE")
		FigGfxInfo.DrawClr = BLUE;

	if (FillColor == "NO_COLOR") 
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;

		if (FillColor == "GREEN")
			FigGfxInfo.FillClr = GREEN;
		else if (FillColor == "YELLOW")
			FigGfxInfo.FillClr = YELLOW;
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