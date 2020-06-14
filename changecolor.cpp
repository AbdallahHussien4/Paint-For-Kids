#include "changecolor.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Line.h"
changecolor :: changecolor (ApplicationManager * pApp):Action(pApp)
{}

void changecolor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
}
ActionType ActType;
void changecolor ::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure * c = pManager->getsel();
	if (c) {
	int countfigures = pManager->getfigcount();
	CLine*l = dynamic_cast <CLine*>(c);
	if (l !=NULL)
		pOut->PrintMessage("Line cannot be filled");
	else 
	{
	
	pOut->CreatColorToolBar();
	ActType=pIn->GetUserAction();
	
	while (ActType == DRAWING_AREA || ActType == STATUS || ActType == EMPTY) {
		pOut->PrintMessage("Choose A Color ");
		ActType = pIn->GetUserAction();
	}

	switch (ActType)	
	{
	case red:

			pOut->PrintMessage("Red color is Selected");
			c->ChngFillClr(RED);
			pManager->setcolored (true);
			UI.FillColor=RED;
			pOut->CreateDrawToolBar();
			break;
		
	
		case green:
			

			pOut->PrintMessage("Green color is Selected");
			c->ChngFillClr(GREEN);
			pManager->setcolored (true);
			UI.FillColor=GREEN;
			pOut->CreateDrawToolBar();
			break;
		

		case black:
		
			pOut->PrintMessage("Black color is Selected");
			c->ChngFillClr(BLACK);
			pManager->setcolored (true);
			UI.FillColor=BLACK;
			pOut->CreateDrawToolBar();
			break;
		

		case blue:
			
			pOut->PrintMessage("Blue color is Selected");
			c->ChngFillClr(BLUE);
			pManager->setcolored (true);
			UI.FillColor=BLUE;
			pOut->CreateDrawToolBar();
			break;
		
		case white:
				
			pOut->PrintMessage("white color is Selected");
			c->ChngFillClr(WHITE);
			pManager->setcolored (true);
			UI.FillColor=WHITE;
			pOut->CreateDrawToolBar();
			break;
		
	pOut->ClearStatusBar();

	}}
}
	else pOut->PrintMessage("No selected shape !!");
}