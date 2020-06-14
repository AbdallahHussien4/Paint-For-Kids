#pragma once
#include "save_by_type.h"
#include "ApplicationManager.h"

save_by_type::save_by_type(ApplicationManager * pApp):Action(pApp)
{
	
}
void save_by_type:: ReadActionParameters(){
	  Output* pOut = pManager->GetOutput();
 	 Input* pIn = pManager->GetInput();
	  pOut->PrintMessage("Please choose A type of figures");
	do{
		
	ActionType Act = pManager->GetUserAction();
		switch (Act)
		{
		case DRAW_LINE:
			type = "LINE";
			break;
		case DRAW_RECT:
			type = "RECTANGLE";
			break;
		case DRAW_ELLIPSE:
			type = "ELLIPSE";
			break;
		case DRAW_RHOMBUS:
			type = "RHOMBUS";
			break;
		case DRAW_TRI:
			type = "TRIANGLE";
			break;
		default:
			break;
		}
	}while( type != "LINE" && type != "RECTANGLE" && type != "ELLIPSE" && type != "RHOMBUS" && type != "TRIANGLE");
		 pOut->PrintMessage("Please Enter file Name");
	 fileName1 = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();                 /////////////
}

void save_by_type:: Execute(){
	 ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ofstream file;
	file.open( fileName1+".txt");
	file << pManager->convertToString(UI.DrawColor) << "\t" << pManager->convertToString(UI.FillColor)<<"\n";
	pManager->savebytype(file , type);
	
	file<<"Graph SAVED";

}
save_by_type::~save_by_type()
{
}
