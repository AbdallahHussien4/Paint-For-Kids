#include "deleteshape.h"
#include"ApplicationManager.h"


deleteshape::deleteshape(ApplicationManager * pApp):Action(pApp)
{
}
void deleteshape::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->getSelectedFig()) {

		pManager->deletesh();
		
		pOut->PrintMessage("the shape is deleted ");
	}
	else pOut->PrintMessage("No selected shape !!");
}


