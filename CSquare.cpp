#include "CSquare.h"
#include <fstream>

CSquare::CSquare(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'S')
{
	Center = P1;
	Radius = P2;
	SquareID = ID;

	// Initalizing Corner 1 and Corner 2 of square to be used in other functions.

	if (abs(Center.x - Radius.x) >= abs(Center.y - Radius.y))
	{
		halfSide = abs(Center.x - Radius.x);
	}
	else
	{
		halfSide = abs(Center.y - Radius.y);
	}

	Corner1.x = Center.x - halfSide;
	Corner2.x = Center.x + halfSide;

	Corner1.y = Center.y - halfSide;
	Corner2.y = Center.y + halfSide;
}

void CSquare::PrintInfo(Output* pOut) const
{
	auto s_ID = std::to_string(ID);
	auto s_Side = std::to_string(halfSide * 2);

	pOut->PrintMessage("Square Selected: ID " + s_ID + ", Side " + s_Side + ".");
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen
	pOut->DrawSquare(Center, Radius, FigGfxInfo, Selected);
}

bool CSquare::isPointinside(int x, int y)
{
	// Checking if point is inside the square

	if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y)
		return true;
	else
		return false;
}
void CSquare::Save(ofstream& OutFile)
{
	OutFile << "S1" << " " << SquareID << " " << Center.x << " " << Center.y << " " << Radius.x;
	OutFile << " " << Radius.y;
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
void CSquare::Load(ifstream& Infile)
{
	string DrawColor, FillColor;
	Infile >> SquareID >> Center.x >> Center.y >> Radius.x >> Radius.y
		>> DrawColor >> FillColor;

	if (DrawColor == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else if (DrawColor == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	else if (DrawColor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	else if (DrawColor == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (DrawColor == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (DrawColor == "BLUE")
		FigGfxInfo.DrawClr = BLUE;

	if (FillColor == "NO_COLOR") {
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
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