#pragma once
#include"Action.h"
#include "..\Actions\Switchtoplay.h"

class Pickandhide : public Action {
protected:
	const char figuretype[5] = { 'R','C','T','H','S'};
	const string figurecolor[6] = { "Black","Blue","Red","Yellow","Orange","Green" };
	//const string both[] = { "Black R","" };
	int count = 0;
	ActionType Mode;
public:
	Pickandhide(ApplicationManager* pApp);
	void Execute();
	virtual void ReadActionParameters();

};
