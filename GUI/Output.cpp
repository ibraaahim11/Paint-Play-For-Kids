#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 41; //ibrahim
	UI.PlayItemWidth = 120; // IBRAHIM

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.ToolBarColor = WHITE; //OMAR
	UI.PenWidth = 3;	//width of the figures frames

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");

	CreateDrawToolBar();
	CreateStatusBar();
}

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const //ibrahim
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu,
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";

	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_BORDER] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";

	MenuItemImages[ITM_R14] = "images\\MenuItems\\Menu_R14.jpg";
	MenuItemImages[ITM_R12] = "images\\MenuItems\\Menu_R12.jpg";
	MenuItemImages[ITM_R2] = "images\\MenuItems\\Menu_R2.jpg";
	MenuItemImages[ITM_R4] = "images\\MenuItems\\Menu_R4.jpg";

	MenuItemImages[ITM_FORWARD] = "images\\MenuItems\\Menu_Forward.jpg";
	MenuItemImages[ITM_BACKWARD] = "images\\MenuItems\\Menu_Backward.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear.jpg";

	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\Menu_Sound.jpg";

	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const   //OMAR
{
	pWind->SetBrush(UI.ToolBarColor);
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

/////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const // ibrahim
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayItemImages[PLAY_ITM_COUNT];

	PlayItemImages[ITM_FIG_TYPE] = "images\\PlayItems\\Play_Shapes.jpg";
	PlayItemImages[ITM_FIG_COLOR] = "images\\PlayItems\\Play_Colors.jpg";
	PlayItemImages[ITM_BOTH] = "images\\PlayItems\\Play_Both.jpg";
	PlayItemImages[ITM_SOUND2] = "images\\PlayItems\\Menu_Sound.jpg";
	PlayItemImages[ITM_DRAW] = "images\\PlayItems\\Play_Draw.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[i], i * UI.PlayItemWidth, 0, UI.PlayItemWidth, UI.ToolBarHeight); //ibrahim

	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////
color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
/// //////////////////////////////////////////////////////////////////////////////////////
int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

// Seif

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

//Seif

void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	double dx = P2.x - P1.x;
	double dy = P2.y - P1.y;
	double radius = sqrt(dx * dx + dy * dy);

	pWind->DrawCircle(P1.x, P1.y, radius, style);
}

void Output::DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int halfSide;

	if (abs(P1.x - P2.x) >= abs(P1.y - P2.y))
	{
		halfSide = abs(P1.x - P2.x);
	}
	else
	{
		halfSide = abs(P1.y - P2.y);
	}

	// Calculate square vertices
	int vertices_x[4];
	int vertices_y[4];  // Array to hold the integer coordinates of vertices

	vertices_x[0] = P1.x - halfSide;
	vertices_x[1] = P1.x + halfSide;
	vertices_x[2] = P1.x + halfSide;
	vertices_x[3] = P1.x - halfSide;

	vertices_y[0] = P1.y - halfSide;
	vertices_y[1] = P1.y - halfSide;
	vertices_y[2] = P1.y + halfSide;
	vertices_y[3] = P1.y + halfSide;

	pWind->DrawPolygon(vertices_x, vertices_y, 4, style); // Drawing a square with 4 vertices
}

void Output::DrawHex(Point p1, Point p2, GfxInfo HexGfxInfo, bool Selected) const   //OMAR
{
	color DrawingClr;
	if (Selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Vertices_x[6];
	int Vertices_y[6];

	int z = (1 / (sqrt(3))) * (abs(p2.y - p1.y));

	if (p2.x < p1.x)
		Vertices_x[0] = p1.x * 2 - p2.x + z;
	else
		Vertices_x[0] = p2.x + z;

	int halfdiagonal = Vertices_x[0] - p1.x;

	if (abs(p2.x - p1.x) < halfdiagonal / 2)
	{
		halfdiagonal = abs(p1.y - p2.y) * 2 / sqrt(3);
		Vertices_x[0] = p1.x + halfdiagonal;
	}

	Vertices_x[1] = Vertices_x[0] - halfdiagonal / 2;
	Vertices_x[2] = Vertices_x[0] - halfdiagonal * 3 / 2;
	Vertices_x[3] = Vertices_x[0] - halfdiagonal * 2;
	Vertices_x[4] = Vertices_x[0] - halfdiagonal * 3 / 2;
	Vertices_x[5] = Vertices_x[0] - halfdiagonal / 2;

	Vertices_y[0] = p1.y;
	Vertices_y[1] = p1.y + halfdiagonal * sqrt(3) / 2;
	Vertices_y[2] = p1.y + halfdiagonal * sqrt(3) / 2;
	Vertices_y[3] = p1.y;
	Vertices_y[4] = p1.y - halfdiagonal * sqrt(3) / 2;
	Vertices_y[5] = p1.y - halfdiagonal * sqrt(3) / 2;

	pWind->DrawPolygon(Vertices_x, Vertices_y, 6, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}