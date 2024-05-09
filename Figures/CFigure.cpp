#include "CFigure.h"

int CFigure::TotalNum = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo, char T) : Type(T)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	CrntDrawClr = FigGfxInfo.DrawClr;
	Selected = false;
	TotalNum++;
	UpdateDrwClrString();
	UpdateFillClrString();
}
void CFigure::SetTotalNum(int num)
{
	TotalNum = num;
}
void CFigure::SetID(int id)
{
	ID = id;
}
char CFigure::GetType() const
{
	return Type;
}
void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::UpdateFillClrString()
{
	if (!FigGfxInfo.isFilled) //check if figure is filled
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
}

void CFigure::UpdateDrwClrString()
{
	if (CrntDrawClr == BLACK)
		DrawColor = "BLACK";

	else if (CrntDrawClr == YELLOW)
		DrawColor = "YELLOW";

	else if (CrntDrawClr == RED)
		DrawColor = "RED";

	else if (CrntDrawClr == ORANGE)
		DrawColor = "ORANGE";

	else if (CrntDrawClr == GREEN)
		DrawColor = "GREEN";

	else if (CrntDrawClr == BLUE)
		DrawColor = "BLUE";
}

void CFigure::ChngDrawClr(color Dclr)
{

	FigGfxInfo.DrawClr = Dclr;
	UpdateDrwClrString();
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
GfxInfo CFigure::GetGfxInfo() const 
{
	return FigGfxInfo;
}
color CFigure::GetCrntDrawClr() const
{
	return CrntDrawClr;
}
void CFigure::SetGfxInfo(GfxInfo FigGfxInfo)
{
	this->FigGfxInfo = FigGfxInfo;
}

void CFigure::SetCrntDrawClr(color crnt)
{
	CrntDrawClr = crnt;
}
}

string CFigure::GetFillColor()const {
	return FillColor;
}