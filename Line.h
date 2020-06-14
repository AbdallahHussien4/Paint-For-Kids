#pragma once
#include "Figures\CFigure.h"
class CLine:public CFigure
{
	private:
	Point Start;	
	Point End;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	CLine(){}
	virtual void Draw(Output* pOut) const;
	bool GetFigure (int x , int y);
	Point getp1();
	Point getp2();
	void setp1(Point);
	void setp2(Point);
	void PrintInfo (Output * pOut);
	string getFigureType ();
	void Save(ofstream &OutFile) ;
	void Load(ifstream &Infile);
	string getDrawColour();
};

