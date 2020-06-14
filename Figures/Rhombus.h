#pragma once
#include "Figures\CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Corner1;	

public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	CRhombus() {}
	virtual void Draw(Output* pOut) const;
	bool GetFigure(int x, int y);
	void PrintInfo(Output* pOut);
	Point getp();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	string getDrawColour();
	string getFigureType();
	string getFillColour();
};

