#pragma once
#include "save.h"
#include "ApplicationManager.h"

save:: save(ApplicationManager * pApp):Action(pApp)
{
	
}
void save:: ReadActionParameters(){
	 Output* pOut = pManager->GetOutput();
 	 Input* pIn = pManager->GetInput();
	 pOut->PrintMessage("Please Enter file Name");
	 fileName = pIn->GetSrting(pOut);
 pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
	 }
void save:: Execute(){
	 ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ofstream file;
	file.open( fileName+".txt");
	file << pManager->convertToString(UI.DrawColor) << "\t" << pManager->convertToString(UI.FillColor)<<"\n";
	pManager->saveAll(file);
	file<<"Graph SAVED";
	 
	 }

save::~save()
{
}
