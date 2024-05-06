#pragma once
#include"Action.h"

class Pickandhide : public Action {
protected:
	string figuretype[5] = { "Rectangles","Squares","Circles","Triangles","Hexagons" };
	string figurecolor[6] = { "Black","Blue","Red","Yellow","Orange","Green" };
	int count = 0;

public:
	Pickandhide(ApplicationManager* pApp);
	void Generate(PlayMenuItem);

};
