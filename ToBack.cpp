#include "ToBack.h"


ToBack::ToBack(ApplicationManager * pApp):Action(pApp)
{
}
void ToBack::Execute(){
	Input* pin=pManager->GetInput();
	Output*pout=pManager->GetOutput();
	s=pManager->getSelectedFig();
	if(s)
	pManager->SendToBack();
	else pout->PrintMessage("No selected shape!!");


}

ToBack::~ToBack(void)
{
}
