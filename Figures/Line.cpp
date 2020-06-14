#include "Line.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a rectangle on the screen	
	pOut->DrawRect(Start, End, FigGfxInfo, Selected);
}