#include "switchtodraw.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"


switchtodraw::switchtodraw(ApplicationManager *pApp):Action(pApp)
{

}

void switchtodraw::Execute(){
	pManager->recopyfiglist();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateDrawToolBar();

	pOut->ClearStatusBar();

}


