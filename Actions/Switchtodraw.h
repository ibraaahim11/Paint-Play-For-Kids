#pragma once
#ifndef SWITCH_TO_DRAW_H
#define SWITCH_TO_DRAW_H

#include"Action.h"
class Switchtodraw :public Action {
	Point p1, p2, p3;
	GfxInfo FigGfxInfo;
public:
	Switchtodraw(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters(); 
	void AutomaticLoad(); //load when switch to draw is called
};
#endif
