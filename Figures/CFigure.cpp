#include "CFigure.h"

int CFigure::TotalNum = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo, char T) : Type(T)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	CrntDrawClr = FigGfxInfo.DrawClr;
	Selected = false;
	TotalNum++;
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

void CFigure::ChngDrawClr(color Dclr)
{
	CrntDrawClr = FigGfxInfo.DrawClr; //get color before changed after selection
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

string CFigure::GetFillColor()const {
	return FillColor;
}