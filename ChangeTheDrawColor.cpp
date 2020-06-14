#include "ChangeTheDrawColor.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ChangeTheDrawColor :: ChangeTheDrawColor (ApplicationManager * pApp):Action(pApp)
{}

void ChangeTheDrawColor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
}

void ChangeTheDrawColor ::Execute()
{
	ActionType ActType;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure * c1 = pManager->getsel();
	if (c1) {
	int countfigures1 = pManager->getfigcount();
	pManager->setcolored (false);
	pOut->CreatColorToolBar();
	ActType = pIn->GetUserAction();

	while (ActType == DRAWING_AREA|| ActType == STATUS|| ActType == EMPTY) {
		pOut->PrintMessage("Choose A Color ");
		ActType = pIn->GetUserAction();
	}

	switch (ActType)
	{
	
	case red:
			
			pOut->PrintMessage("Red color is Selected");
			c1->ChngDrawClr(RED);
			UI.DrawColor = RED;
			c1->SetSelected(false);
			pOut->CreateDrawToolBar();
			break;
		

		case green:
				

		
			pOut->PrintMessage("Green color is Selected");
			c1->ChngDrawClr(GREEN);
			UI.DrawColor = GREEN;
			c1->SetSelected(false);
			pOut->CreateDrawToolBar();
			break;
		
		case black:
				
			pOut->PrintMessage("Black color is Selected");
			c1->ChngDrawClr(BLACK);
			UI.DrawColor = BLACK;
			c1->SetSelected(false);
			pOut->CreateDrawToolBar();
			break;
		

		case blue:
	
			pOut->PrintMessage("Blue color is Selected");
			
			c1->ChngDrawClr(BLUE);
			UI.DrawColor = BLUE;
			c1->SetSelected(false);
			pOut->CreateDrawToolBar();
			break;
		
		case white:
		
			pOut->PrintMessage("white color is Selected");
			
			c1->ChngDrawClr(WHITE);
			UI.DrawColor = WHITE;
	        c1->SetSelected(false);
			pOut->CreateDrawToolBar();
			break;
		
		
	}
	pOut->ClearStatusBar();
}
	else pOut->PrintMessage("No selected shape !!");
}



