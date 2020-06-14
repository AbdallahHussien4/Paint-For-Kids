#pragma once
#include "Figures\CFigure.h"

class CTriangle: public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;

public:
	CTriangle(Point , Point,Point, GfxInfo FigureGfxInfo );
	CTriangle() {}
	virtual void Draw(Output* pOut) const;
	bool GetFigure (int x , int y);
	Point getp1();
	Point getp2();
	Point getp3();
	void setp1(Point);
	void setp2(Point);
	void setp3(Point);
	void PrintInfo(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	string getFigureType () ;
	string getDrawColour();
	string getFillColour();
};

