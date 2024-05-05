#include "CRectangle.h"
#include <fstream>




CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'R')
{
	Corner1 = P1;
	Corner2 = P2;
	RectID = ID;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isPointinside(int x, int y)
{
	// Checking if point is inside rectangle in all ca,es of user's rectangle/

	if (Corner1.x < Corner2.x)
	{
		if (Corner1.y > Corner2.y)
		{
			if (x >= Corner1.x && x <= Corner2.x && y <= Corner1.y && y >= Corner2.y) return true;
			else return false;
		}
		else
		{
			if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y) return true;
			else return false;
		}

	}
	else
	{
		if (Corner1.y > Corner2.y)
		{
			if (x >= Corner2.x && x <= Corner1.x && y >= Corner2.y && y <= Corner1.y) return true;
			else return false;
		}
		else
		{
			if (x >= Corner2.x && x <= Corner1.x && y >= Corner1.y && y <= Corner2.y) return true;
			else return false;
		}


	}






}
void CRectangle::Save(ofstream& OutFile) // omar
{
	OutFile << "R1" << " " << RectID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y;
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
void CRectangle::Load(ifstream& Infile)
{
	string DrawColor, FillColor;
	if (IsSelected())
		SetSelected(false);
	Infile >> RectID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y
		>> DrawColor >> FillColor;

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
;
}