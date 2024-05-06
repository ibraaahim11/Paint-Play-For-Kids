#include "PasteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\CTriangle.h"
#include "..\CCircle.h"
#include "..\CSquare.h"
#include "..\CHexagon.h"


PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{}

void PasteAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	Cptr = pManager->GetClipboard(); //Get the Copied figure from clipboard
 
	if (!(Cptr == NULL))
	{
		PType = Cptr->GetType();
		pOut->PrintMessage("Click Where you want to paste Copied Figure!");
		pIn->GetPointClicked(p.x, p.y); //Center of pasted figure

	}
	else
		pOut->PrintMessage("You Did Not Copy A Figure!"); // if you press paste icon without copying a figure
}

void PasteAction::Execute()
{
	//Reads Center of paster figure and get clipboard figure
		ReadActionParameters();
		if (!(Cptr == NULL)) // if there is no figure in clipboard it should not run the code
		{

			switch (PType)
			{
			case 'R': // case the clipboard figure is rectangle
			{
				Point Corner1, Corner2; // calculating the two corners of rectangle
				Corner1.x = p.x - ((CRectangle*)Cptr)->GetWidth() / 2;
				Corner1.y = p.y - ((CRectangle*)Cptr)->GetHeight() / 2;
				Corner2.x = p.x + ((CRectangle*)Cptr)->GetWidth() / 2;
				Corner2.y = p.y + ((CRectangle*)Cptr)->GetHeight() / 2;
				CRectangle* R = new CRectangle(Corner1, Corner2, Cptr->GetGfxInfo());
				pManager->AddFigure(R);
				break;
			} 
			case 'T': // case the clipboard figure is triangle
			{
				Point p1, p2, p3, Center; //calculating the three vertices by knowing the distance between each vertix and center
				Center = Cptr->GetCenter();
				p1.x = ((CTriangle*)Cptr)->GetVertix1().x - Center.x + p.x;
				p1.y = ((CTriangle*)Cptr)->GetVertix1().y - Center.y + p.y;
				p2.x = ((CTriangle*)Cptr)->GetVertix2().x - Center.x + p.x;
				p2.y = ((CTriangle*)Cptr)->GetVertix2().y - Center.y + p.y;
				p3.x = ((CTriangle*)Cptr)->GetVertix3().x - Center.x + p.x;
				p3.y = ((CTriangle*)Cptr)->GetVertix3().y - Center.y + p.y;
				CTriangle* T = new CTriangle(p1, p2, p3, Cptr->GetGfxInfo());
				pManager->AddFigure(T);
				break;
			}
			case 'S':// case the clipboard figure is square
			{
				Point p1;//calculating second point of square
				p1.y = p.y;
				p1.x = p.x + abs(((CSquare*)Cptr)->GetCorner1().x - ((CSquare*)Cptr)->GetCenter().x);
				CSquare* S = new CSquare(p, p1, Cptr->GetGfxInfo());
				pManager->AddFigure(S);
				break;
			}
			case 'H':// case the clipboard figure is hexagon
			{
				Point p1;//calculating second point of hexagon
				p1.y = p.y;
				p1.x = p.x + ((CHexagon*)Cptr)->GetXVertix1() - ((CHexagon*)Cptr)->GetCenter().x;
				CHexagon* H = new CHexagon(p, p1, Cptr->GetGfxInfo());
				pManager->AddFigure(H);
				break;
			}
			case 'C':// case the clipboard figure is circle
			{
				Point p1; //calculating second point of circle
				p1.x = p.x + ((CCircle*)Cptr)->GetRadius().x - ((CCircle*)Cptr)->GetCenter().x;
				p1.y = p.y + ((CCircle*)Cptr)->GetRadius().y - ((CCircle*)Cptr)->GetCenter().y;
				CCircle* C = new CCircle(p, p1, Cptr->GetGfxInfo());
				pManager->AddFigure(C);
				break;
			}
			}
		}
}