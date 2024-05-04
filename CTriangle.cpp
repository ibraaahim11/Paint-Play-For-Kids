#include "CTriangle.h"
#include <fstream>

int CTriangle::SelectedNum = 0;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'T')
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
	OutFile << "TRIANGLE " << "  " << TriID << "  " << Vertix1.x << "  " << Vertix1.y << "  " << Vertix2.x << "  ";
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