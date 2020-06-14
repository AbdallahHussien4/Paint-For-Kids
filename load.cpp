#pragma once
#include "load.h"
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTRIAction.h"
#include "Actions\AddRhombusAction.h"
#include "Actions\AddEllipseAction.h"
#include"Line.h"
#include"Triangle.h"
#include"Ellipse.h"
#include"Figures\CRectangle.h"
#include"Rhombus.h"
#include"DEFS.h"
load::load(ApplicationManager * pApp):Action(pApp)
{

}
void load:: ReadActionParameters(){

	 Output* pOut = pManager->GetOutput();
 	 Input* pIn = pManager->GetInput();
	 pOut->PrintMessage("Please Enter File Name");
	 fileName = pIn->GetSrting(pOut);
}
void load:: Execute(){
	CFigure* Cfig = NULL;
	string figName , drawColour , fillColour , figDrawColour , figFillColour;
	int figNum ; Point p1 , p2 , p3;  GfxInfo figInfo;
	int i;
	ifstream file;
	 Output* pOut = pManager->GetOutput();
 	 Input* pIn = pManager->GetInput();
	ReadActionParameters();
	file.open(fileName+".txt");
	//pOut->ClearDrawArea();
	if(file.fail()){              ////////// check the validity of file
		pOut->PrintMessage("UnFounded file");
		return;
	}
	file >> drawColour  >> fillColour;
	UI.DrawColor = pManager->convertToColour(drawColour);
	
	UI.FillColor = pManager->convertToColour(fillColour);

	pManager->loadFig();
	file >> figNum;

	while(figNum){
	
		file >> figName;
		
		if(figName == "RECTANGLE")
		{	//file >> p1.x >> p1.y >> p2.x >> p2.y >> figDrawColour >> figFillColour ;	
			
			Cfig = new CRectangle();
			
			}
		
		else if(figName == "RHOMBUS")
			{
				//file >> p1.x >> p1.y >> figDrawColour >> figFillColour ;	
			
		Cfig = new CRhombus() ;}
		
	else if(figName == "LINE"){
			//file >> p1.x >> p1.y >> p2.x >> p2.y >> figDrawColour >> figFillColour ;	
			
			Cfig = new CLine() ;}
		
	else if(figName == "TRIANGLE"){
			//file >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> figDrawColour >> figFillColour ;	
			
			Cfig = new CTriangle() ;}
		
	else if(figName == "ELLIPSE"){
			//file >> i >>  figDrawColour >> figFillColour >> p1.x >> p1.y;

			Cfig = new CEllipse() ;

			//dynamic_cast<CEllipse*>(Cfig)
		}
		
	Cfig->Load(file);

	pManager->AddFigure(Cfig);
	
	figNum--;
}

	pManager->UpdateInterface();

	pOut->PrintMessage("loading completed");

	pOut->ClearStatusBar();
	pOut->CreateStatusBar();










}


load::~load()
{
}
