#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle :: GetFigure (int x , int y)
{
	if((x >=Corner1.x&& x <= Corner2.x && y >=Corner1.y && y<=Corner2.y)|| (x <=Corner1.x&& x >= Corner2.x && y <=Corner1.y && y>=Corner2.y)) 
		return true;
	else
		if ((x>=Corner2.x && x<=Corner1.x && y>=Corner1.y && y<=Corner2.y) || (x>=Corner1.x && x<=Corner2.x && y>=Corner2.y && y<= Corner1.y))
			return true ;
		else
			return false;
}
Point CRectangle::getp1() {
	return Corner1;
}
Point CRectangle::getp2() {
	return Corner2;
}
void CRectangle::setp1(Point p) {
	Corner1 = p;
}
void CRectangle::setp2(Point p) {
	Corner2 = p;
}
void CRectangle :: PrintInfo (Output* pOut)
{
	int length = abs (Corner2.x-Corner1.x);
	int width = abs (Corner2.y-Corner1.y);
	int area = length * width ;
	pOut->PrintMessage ("The ID is : "+ std :: to_string (getid()) + "  The Length is : "+std :: to_string (length)+"  The width is : "+std :: to_string (width)+"  The Area is : "+std :: to_string (area));
}
string CRectangle:: getFigureType (){

	return"RECTANGLE";
}
string CRectangle:: getDrawColour(){

	color b;
	b=FigGfxInfo.DrawClr;
	if(b == RED )
		return "RED";
	else if(b == WHITE )
		return "WHITE";
	else if(b == BLACK )
		return "BLACK";
	else if(b == GREEN )
		return "GREEN";
	else if(b == BLUE )
		return "BLUE";
	else
	
		return "BLACK";
	
}
string CRectangle:: getFillColour(){
	color b;
	if(FigGfxInfo.isFilled){
	b=FigGfxInfo.FillClr;
	if(b == RED )
		return "RED";
	else if(b == WHITE )
		return "WHITE";
	else if(b == BLACK )
		return "BLACK";
	else if(b == GREEN )
		return "GREEN";
	else if(b == BLUE )
		return "BLUE";
	}
	else
		return "NonFill";

}
void  CRectangle :: Save(ofstream &OutFile){
	OutFile << "RECTANGLE"<<"\t" << Id++ <<"\t"<<getDrawColour() << "\t"<< getFillColour()<<"\t"<<Corner1.x << "\t"<< Corner1.y << "\t"<<Corner2.x << "\t"<< Corner2.y <<endl;  

}

void CRectangle:: Load(ifstream &Infile){
	
	string s;

	Infile >> this->ID >>s;
	this->FigGfxInfo.DrawClr = convertToColour(s);

	Infile >> s;
	if ( s == "NonFill")
		this->FigGfxInfo.isFilled= false;
	else
	{
		this->FigGfxInfo.FillClr = convertToColour(s);
		this->FigGfxInfo.isFilled= true;
	}
	//this->FigGfxInfo.BorderWdth = ;
	Infile >> this->Corner1.x >> this->Corner1.y >> this->Corner2.x >> this->Corner2.y;
	this->Selected =false;
}
