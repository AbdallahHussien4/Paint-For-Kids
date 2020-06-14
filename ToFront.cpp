#include "ToFront.h"


ToFront::ToFront(ApplicationManager * pApp):Action(pApp)
{
}
void ToFront::Execute(){
	Input* pin=pManager->GetInput();
	Output*pout=pManager->GetOutput();
	s=pManager->getSelectedFig();
	if(s)
	pManager->SendToFront();
	else pout->PrintMessage("No selected shape!!");


}

ToFront::~ToFront(void)
{
}
