#include "Triangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
	

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}
bool CTriangle :: GetFigure (int x , int y)
{
	double area , s1 ,s2 ,s3;
	double sum =0;
	area = abs((Corner1.x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-Corner2.y))/2.0);
	s1 = abs((x*(Corner1.y-Corner2.y)+Corner1.x*(Corner2.y-y)+Corner2.x*(y-Corner1.y))/2.0);//between corners 1&2
	s2 = abs((x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-y)+Corner3.x*(y-Corner2.y))/2.0);//between corners 2&3
	s3 = abs((x*(Corner1.y-Corner3.y)+Corner1.x*(Corner3.y-y)+Corner3.x*(y-Corner1.y))/2.0);//between corners 3&1
	sum = s1+s2+s3;
	if (area == sum)
		return true;
	else 
		return false;
}
Point CTriangle::getp1() {
	return Corner1;
}
Point CTriangle::getp2() {
	return Corner2;
}
Point CTriangle::getp3() {
	return Corner3;
}
void CTriangle::setp1(Point p) {
	Corner1 = p;
}
void CTriangle::setp2(Point p) {
	Corner2 = p;
}
void CTriangle::setp3(Point p) {
	Corner3 = p;
}
void CTriangle :: PrintInfo(Output* pOut)
{
	int area = abs((Corner1.x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-Corner2.y))/2);
	pOut->PrintMessage ("The ID is : "+ std :: to_string (getid ())+"  The First Point is : "+ "("+ std :: to_string (Corner1.x) + ","+std :: to_string (Corner1.y)+")"+"  The Second Point is : "+"("+std :: to_string (Corner2.x) + ","+std :: to_string (Corner2.y)+")" +"  The Third Point is : "+"("+std :: to_string (Corner3.x) + ","+std :: to_string (Corner3.y)+")" + "  The Area is : "+std :: to_string(area));
}
string CTriangle :: getFigureType () {
	return "TRIANGLE";
}
string CTriangle:: getDrawColour(){

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
}
string CTriangle:: getFillColour(){
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
void  CTriangle::Save(ofstream &OutFile) {
	OutFile << "TRIANGLE" << "\t" << Id++ << "\t" << getDrawColour() << "\t" << getFillColour() << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "  " << "\t" << Corner3.x << "\t" << Corner3.y << endl;

}
void CTriangle:: Load(ifstream &Infile){
	
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
	Infile >> this->Corner1.x >> this->Corner1.y >> this->Corner2.x >> this->Corner2.y >> this->Corner3.x >> this->Corner3.y;
	//this->FigGfxInfo.BorderWdth = ;
	this->Selected =false;
}