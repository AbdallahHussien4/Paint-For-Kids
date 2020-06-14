#include "Rhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRHOM(Corner1, FigGfxInfo, Selected);
}
