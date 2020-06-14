#include "Ellipse.h"
CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a rectangle on the screen	
	pOut->DrawEllipse(Corner1,FigGfxInfo, Selected);
}
//bool CEllipse :: GetFigure (int x , int y)
//{
//double a, b;
//a =sqrt(pow((Corner1.x +30-Corner1.x),2));
//b =sqrt(pow((Corner1.y+50 - Corner1.y),2)); 
//if ((pow (x-Corner1.x,2)/pow(a,2))+(pow(y-Corner1.y,2)/pow(b,2))<=1)
//	return true;
//else return false;
//}
void CEllipse :: PrintInfo(Output* pOut)
{
	float a,b;
a =sqrt(pow((Corner1.x +30-Corner1.x),2));
b =sqrt(pow((Corner1.y+50 - Corner1.y),2)); 
	float area = 3.14*a*b;
pOut->PrintMessage ("The ID is : "+ std :: to_string (getid()) +"  The Center Point is : " + "("+ std :: to_string (Corner1.x)+ ","+std :: to_string (Corner1.y)+")" + "  The Area is : "+ std :: to_string(area));
}
Point CEllipse::getp() {
	return Corner1;
}
string CEllipse :: getFigureType () {
	return "ELLIPSE";
}
bool CEllipse :: GetFigure (int x , int y)
{
int a, b;
a =sqrt(pow((Corner1.x +30-Corner1.x),2));
b =sqrt(pow((Corner1.y+50 - Corner1.y),2)); 
if ((pow (x-Corner1.x,2)/pow(a,2))+(pow(y-Corner1.y,2)/pow(b,2))<=1)
	return true;
else return false;
}
string CEllipse:: getDrawColour(){

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
string CEllipse:: getFillColour(){
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
void  CEllipse::Save(ofstream &OutFile) {
	OutFile << "ELLIPSE" << "\t" << Id++ << "\t" << getDrawColour() << "\t" << getFillColour() << "\t" << Corner1.x << "\t" << Corner1.y << endl;

}
void CEllipse:: Load(ifstream &Infile){
	
	string s;

	
	Infile >> this->Id >> s;


	this->FigGfxInfo.DrawClr = convertToColour(s);

	Infile >> s;
	if ( s == "NonFill")
		this->FigGfxInfo.isFilled= false;
	else
	{
		this->FigGfxInfo.FillClr = convertToColour(s);
		this->FigGfxInfo.isFilled= true;
	}
	Infile >> this->Corner1.x >> this->Corner1.y;
	//this->FigGfxInfo.BorderWdth = ;
	this->Selected =false;
}