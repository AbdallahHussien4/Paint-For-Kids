#include "Rhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	
string CRhombus :: getFigureType () {
	return "RHOMBUS";
}
string CRhombus:: getDrawColour(){

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
string CRhombus:: getFillColour(){
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
void  CRhombus::Save(ofstream &OutFile) {
	OutFile << "RHOMBUS" << "\t" << Id++ << "\t" << getDrawColour() << "\t" << getFillColour() << "\t" << Corner1.x << "\t" << Corner1.y << endl;

}

void CRhombus:: Load(ifstream &Infile){
	
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
	Infile >> this->Corner1.x >> this->Corner1.y;
	this->Selected =false;
}
void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRHOM(Corner1, FigGfxInfo, Selected);
}

bool CRhombus :: GetFigure (int x , int y)
{
double d1 ,d2,s1,s2,s3,s4;
double area =0;
double sum =0;
d1 = (Corner1.x * (Corner1.y-(Corner1.y+70))+ (Corner1.x+40)*((Corner1.y+70)-(Corner1.y-70))+Corner1.x * ((Corner1.y-70)-Corner1.y))/2.0;
d2 = (Corner1.x*(Corner1.y-(Corner1.y-70))+(Corner1.x-40)*((Corner1.y-70)-(Corner1.y+70))+Corner1.x * ((Corner1.y+70)-Corner1.y))/2.0;
area = d1+d2;
s1 = abs((x*((Corner1.y-70)-Corner1.y)+Corner1.x*(Corner1.y-y)+(Corner1.x+40)*(y-(Corner1.y-70)))/2.0);//between corners 1&2
s2 = abs((x*(Corner1.y-(Corner1.y+70))+(Corner1.x+40)*((Corner1.y+70)-y)+Corner1.x*(y-Corner1.y))/2.0);//between corners 2&3
s3 = abs((x*((Corner1.y+70)-Corner1.y)+Corner1.x*(Corner1.y-y)+(Corner1.x-40)*(y-(Corner1.y+70)))/2.0);//between corners 3&4
s4 = abs((x*(Corner1.y-(Corner1.y-70))+(Corner1.x-40)*((Corner1.y-70)-y)+Corner1.x*(y-Corner1.y))/2.0);//between corners 4&1
sum = s1+s2+s3+s4;
if (sum == area)
	return true;
else
	return false;
}
void CRhombus :: PrintInfo(Output* pOut)
{
int d1,d2,area;
d1 = (Corner1.x * (Corner1.y-(Corner1.y+70))+ (Corner1.x+40)*((Corner1.y+70)-(Corner1.y-70))+Corner1.x * ((Corner1.y-70)-Corner1.y))/2;
d2 = (Corner1.x*(Corner1.y-(Corner1.y-70))+(Corner1.x-40)*((Corner1.y-70)-(Corner1.y+70))+Corner1.x * ((Corner1.y+70)-Corner1.y))/2;
area = d1+d2;
int Ld1 , Ld2;
Ld1 = 140;
Ld2 = 80;
pOut->PrintMessage ("The ID is : "+ std :: to_string (getid()) + "  The Length of Diagonal 1 is : " + std :: to_string (Ld1) + "  The Length of Diagonal 2 is : " +std :: to_string (Ld2) + "  The Area is : " +std :: to_string (area));
} 
Point CRhombus::getp() {
	return Corner1;
}