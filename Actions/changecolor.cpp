#include "changecolor.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

changecolor :: changecolor (ApplicationManager * pApp):Action(pApp)
{}

void changecolor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
}
void changecolor ::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatColorToolBar();

	pOut->ClearStatusBar();
}
