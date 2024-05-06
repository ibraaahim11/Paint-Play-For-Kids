#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'R')
{
	Corner1 = P1;
	Corner2 = P2;
	ID = TotalNum;
	Height = abs(P1.y - P2.y);
	Width = abs(P1.x - P2.x);
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output* pOut) const
{
	auto s_ID = std::to_string(ID);
	auto s_Height = std::to_string(Height);
	auto s_Width = std::to_string(Width);

	pOut->PrintMessage("Rectangle Selected: ID " + s_ID + ", Fill Color " + FillColor + ", Height " + s_Height + ", Width " + s_Width + ".");
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

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " "
		<< Corner2.x << " " << Corner2.y;  //writing the figure parameters
	UpdateDrwClrString();
	UpdateFillClrString();

	OutFile << " " << DrawColor << " " << FillColor << endl;
}
void CRectangle::Load(ifstream& Infile)
{
	if (IsSelected())
		SetSelected(false); //deselect so it can be selected when loaded
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y
		>> DrawColor >> FillColor; //reading figure parameters from file

	if (DrawColor == "GREEN")  //converting color strings to color to draw figure with specific color
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

	if (FillColor == "NO_COLOR") //check if figure is filled
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
	;
}