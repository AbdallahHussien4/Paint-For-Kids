#pragma once
#include "Figures\CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;	
	
public:
	CEllipse(Point,GfxInfo FigureGfxInfo );
	CEllipse(){}
	virtual void Draw(Output* pOut) const;
    bool GetFigure (int x , int y);
	Point getp();
	void PrintInfo(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	string getDrawColour();
	string getFigureType ();
	string getFillColour();
};

