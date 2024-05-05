#include "CFigure.h"

int CFigure::ID = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo, char T) : Type(T)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	CrntDrawClr = FigGfxInfo.DrawClr;
	Selected = false;
	ID++;
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