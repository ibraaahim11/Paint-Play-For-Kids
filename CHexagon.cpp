#include "CHexagon.h"

#include <fstream>

CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'H')
{
	Center = P1;
	Radius = P2;
	ID = TotalNum;

	Calculate_Vertices();

	Height = Vertices_y[0] - Vertices_y[5];

	Width = Vertices_x[0] - Vertices_x[3];
}
void CHexagon::Calculate_Vertices()
{
	// Calculating Eeach vertix in the hexagon and storing its x value in Vertices_x and y value in Vertices_y
	int z = (1 / (sqrt(3))) * (abs(Radius.y - Center.y));

	if (Radius.x < Center.x)
		Vertices_x[0] = Center.x * 2 - Radius.x + z;
	else
		Vertices_x[0] = Radius.x + z;

	int halfdiagonal = Vertices_x[0] - Center.x;

	if (abs(Radius.x - Center.x) < halfdiagonal / 2)
	{
		halfdiagonal = abs(Center.y - Radius.y) * 2 / sqrt(3);
		Vertices_x[0] = Center.x + halfdiagonal;
	}

	Vertices_x[1] = Vertices_x[0] - halfdiagonal / 2;
	Vertices_x[2] = Vertices_x[0] - halfdiagonal * 3 / 2;
	Vertices_x[3] = Vertices_x[0] - halfdiagonal * 2;
	Vertices_x[4] = Vertices_x[0] - halfdiagonal * 3 / 2;
	Vertices_x[5] = Vertices_x[0] - halfdiagonal / 2;

	Vertices_y[0] = Center.y;
	Vertices_y[1] = Center.y + halfdiagonal * sqrt(3) / 2;
	Vertices_y[2] = Center.y + halfdiagonal * sqrt(3) / 2;
	Vertices_y[3] = Center.y;
	Vertices_y[4] = Center.y - halfdiagonal * sqrt(3) / 2;
	Vertices_y[5] = Center.y - halfdiagonal * sqrt(3) / 2;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a Hexagonon the screen
	pOut->DrawHex(Center, Radius, FigGfxInfo, Selected);
}
void CHexagon::PrintInfo(Output* pOut) const
{
	auto s_ID = std::to_string(ID);
	auto s_Height = std::to_string(Height);
	auto s_Width = std::to_string(Width);

	pOut->PrintMessage("Hexagon Selected: ID " + s_ID + ", Fill Color " + FillColor + ", Height " + s_Height + ", Width " + s_Width + ".");
}

bool CHexagon::isPointinside(int x, int y)
{
	// Splitting the hexagon into 6 triangle and using the Barycentric Coordinates method
	// Each triangle has 3 vertices, one of them being the center
	Point Vertix1, Vertix2, Vertix3;
	Vertix3 = Center;

	for (int i = 0; i < 6; i++)
	{
		Vertix1.x = Vertices_x[i];
		Vertix1.y = Vertices_y[i];
		if (i == 5)
		{
			// Array consisits of 6 vertices only. So, in the final loop the second vertix of the triangle will be the very first vertix.
			Vertix2.x = Vertices_x[0];
			Vertix2.y = Vertices_y[0];
		}
		else
		{
			Vertix2.x = Vertices_x[i + 1]; Vertix2.y = Vertices_y[i + 1];
		}

		// Calculating (u,v,w)
		double det = (Vertix2.y - Vertix3.y) * (Vertix1.x - Vertix3.x) + (Vertix3.x - Vertix2.x) * (Vertix1.y - Vertix3.y);
		double factor_u = (Vertix2.y - Vertix3.y) * (x - Vertix3.x) + (Vertix3.x - Vertix2.x) * (y - Vertix3.y);
		double factor_v = (Vertix3.y - Vertix1.y) * (x - Vertix3.x) + (Vertix1.x - Vertix3.x) * (y - Vertix3.y);
		double u = factor_u / det;
		double v = factor_v / det;
		double w = 1.0 - u - v;

		if (w >= 0 && w <= 1 && v >= 0 && v <= 1 && u >= 0 && u <= 1)
			return true;
	}
	// if it is not in any of the 6 triangles then it isn't in the hexagon
	return false;
}
void CHexagon::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Center.x << " " << Center.y << " " << Radius.x;
	OutFile << " " << Radius.y;//writing the figure parameters

	UpdateDrwClrString();
	UpdateFillClrString();

	OutFile << " " << DrawColor << " " << FillColor << endl;
}
void CHexagon::Load(ifstream& Infile)
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
Point CHexagon::GetCenter()
{
	return Center;
}
int CHexagon::GetXVertix1()
{
	return Vertices_x[0];
}
Point CHexagon::GetRadius()
{
	return Radius;
}