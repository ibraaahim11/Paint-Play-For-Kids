#include "CHexagon.h"

#include <fstream>


int CHexagon::SelectedNum = 0;


CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo, 'H')
{
	Center = P1;
	Radius = P2;

}
void CHexagon::Calculate_Vertices()
{
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

bool CHexagon::isPointinside(int x, int y)
{
	Calculate_Vertices();

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
	OutFile << "HEXAGON " << "  " << ID++ << "  " << Center.x << "  " << Center.y << "  " << Radius.x;
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