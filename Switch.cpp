#include "Switch.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

Switch:: Switch (ApplicationManager * pApp):Action(pApp)
{}

void Switch::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
}
void Switch::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->getIsCut())
		pOut->PrintMessage("There is a cutted shape ,please paste");
	else {
		pManager->copyfiglist();

		pOut->CreatePlayToolBar();

		pOut->ClearStatusBar();
	}
}
