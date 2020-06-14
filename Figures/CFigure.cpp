#include "CFigure.h"
int CFigure:: Id = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
CFigure::CFigure(){}
GfxInfo CFigure::getg() {
	return FigGfxInfo;
}
void CFigure::setg(GfxInfo g) {
	FigGfxInfo = g;
}
void CFigure:: setID(int n) {
	 Id = n;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure:: convertToColour(string c){

	if(c == "RED" )
		return RED ;
	else if(c =="WHITE" )
		return WHITE ;
	else if(c == "BLACK" )
		return BLACK;
	else if(c == "GREEN" )
		return GREEN;
	else if(c == "MAGENTA" )
		return MAGENTA;
	else if(c == "TURQUOISE" )
		return TURQUOISE;
	//return "NONE-FIlled";

}
bool CFigure :: GetFigure (int x , int y)
{
return 0;
}
void CFigure :: PrintInfo (Output* pOut)
{

}

void CFigure :: setid (int i)
{
	ID = i;
}
int CFigure :: getid ()
{
return ID;
}
color CFigure::getcolor() {
	return FigGfxInfo.DrawClr;
}
