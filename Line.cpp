#include "Line.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
}
string CLine::getDrawColour() {

	color b;
	b = FigGfxInfo.DrawClr;
	if (b == RED)
		return "RED";
	else if (b == WHITE)
		return "WHITE";
	else if (b == BLACK)
		return "BLACK";
	else if (b == GREEN)
		return "GREEN";
	else if (b == BLUE)
		return "BLUE";
	else 

		return "BLACK";

}

string CLine :: getFigureType () {
	return "LINE";
}
void  CLine::Save(ofstream &OutFile) {
	OutFile << "LINE" << "\t" << Id++ << "\t" << getDrawColour() << "\t" << "NonFill" << "\t" << Start.x << "\t" << Start.y << "\t" << End.x << "\t" << End.y << endl;

}
	void CLine:: Load(ifstream &Infile){
	
	string s;

	Infile >> this->ID >>s;
	this->FigGfxInfo.DrawClr = convertToColour(s);
	this->FigGfxInfo.isFilled = false;
	
	Infile>>this->Start.x >> this->End.y;
	this->Selected =false;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a rectangle on the screen	
	pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}
bool CLine :: GetFigure (int x , int y)
{
double m,c;
m = (End.y-Start.y)*1.0/(End.x-Start.x);
c = ((End.y+Start.y)-(m*(End.x+Start.x)))/2.0;
if ((abs(y - m*x - c)/sqrt(1+pow(m,2)*1.0)) <=5 && ((y>=Start.y && y<=End.y && x>=End.x && x<=Start.x) ||(y >=End.y && y<=Start.y && x>=Start.x && x<=End.x)))
	return true;
else 
	if ((abs(y - m*x - c)/sqrt(1+pow(m,2)*1.0)) <=5 &&(y >= Start.y && y <= End.y && x >= Start.x && x<=End.x)||(y>=End.y && y<=Start.y && x>=End.x && x<=Start.x))
	return true;
else 
	return false;
}
Point CLine::getp1() {
	return Start;
}
Point CLine::getp2() {
	return End;
}
void CLine::setp1(Point p) {
	Start = p;
}
void CLine::setp2(Point p) {
	End = p;
}
void CLine :: PrintInfo (Output * pOut)
{
pOut->PrintMessage ("The ID is : "+ std :: to_string (getid())+"  The Start Point is : "+ "("+ std :: to_string (Start.x)+ ","+std :: to_string (Start.y)+")"+"  The End Point is : "+"("+std :: to_string (End.x) + ","+std :: to_string (End.y)+")");
}