#include "Voice.h"


Voice:: Voice (ApplicationManager * pApp):Action(pApp)
{
}
void Voice:: Execute(){
	Input* pin=pManager->GetInput();
	Output*pout=pManager->GetOutput();
	if(pManager->getvoice())
		{pManager->setvoice(false);
	pout->PrintMessage("Voice is Muted");}
	else{
		pManager->setvoice(true);
		pout->PrintMessage("Voice is Activated");}
	

}

Voice::~Voice(void)
{
}
