#include "AddLineAction.h"

#include "Figures\Line.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{}

void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at Start Point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at End Point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	while (P1.y < 50 || P2.y < 50 || P1.y>600 || P2.y>600)
	{
		pOut->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar ,click 2 points");
		pIn->GetPointClicked(P1.x, P1.y);
		pIn->GetPointClicked(P2.x, P2.y);
	}
	
	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute() 
{
	if (pManager->getvoice())
	{
		sndPlaySound(TEXT("sounds\\line.wav"), SND_FILENAME | SND_ASYNC);
	}
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a Line with the parameters read from the user
	CLine * L=new CLine(P1, P2, LineGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(L);
}

