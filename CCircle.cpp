#include "CCircle.h"
#include <fstream>

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'C')
{
	Center = P1;
	Radius = P2;
	ID = TotalNum;

	Radius_length = sqrt(pow((Radius.x - Center.x), 2) + pow((Radius.y - Center.y), 2));
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a Circle on the screen
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut) const
{
	auto s_ID = std::to_string(ID);
	auto s_Radius = std::to_string(int(Radius_length));

	pOut->PrintMessage("Circle Selected: ID " + s_ID + ", Fill Color " + FillColor + ", Radius " + s_Radius + ".");
}

bool CCircle::isPointinside(int x, int y)
{
	// Calculate the distance between the center of the circle and the point
	double distance = sqrt(pow((Center.x - x), 2) + pow((y - Center.y), 2));

	if (distance <= Radius_length)
		return true;
	else
		return false;
}
void CCircle::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Center.x << " " << Center.y << " " << Radius.x;
	OutFile << " " << Radius.y; //writing the figure parameters

	UpdateDrwClrString();
	UpdateFillClrString();

	OutFile << " " << DrawColor << " " << FillColor << endl;
}
void CCircle::Load(ifstream& Infile)
{
	if (IsSelected())
		SetSelected(false); //deselect so it can be selected when loaded
	Infile >> ID >> Center.x >> Center.y >> Radius.x >> Radius.y
		>> DrawColor >> FillColor;//reading figure parameters from file

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
}