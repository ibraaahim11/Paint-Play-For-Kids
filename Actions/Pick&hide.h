#pragma once
#include"Action.h"
#include "..\Actions\Switchtoplay.h"

class Pickandhide : public Action {
protected:
	char figuretype[5]; //= { 'R','C','T','H','S' };
	string figurecolor[6] = { "BLACK","BLUE","RED","YELLOW","ORANGE","GREEN" };
	int count = 0;
	ActionType Mode;
public:
	Pickandhide(ApplicationManager* pApp);
	void Execute();
	virtual void ReadActionParameters();

};
