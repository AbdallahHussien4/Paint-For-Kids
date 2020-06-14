#include "AddTRIAction.h"


#include "Triangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddTRIAction::AddTRIAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTRIAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P3.x, P3.y);

	while (P1.y < 50 || P2.y < 50 || P3.y < 50 || P1.y>600 || P2.y>600 || P3.y>600)
	{
		pOut->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , click 3 points ");
		pIn->GetPointClicked(P1.x, P1.y);
		pIn->GetPointClicked(P2.x, P2.y);
		pIn->GetPointClicked(P3.x, P3.y);
	}
	if (pManager->getcolored()==true)
		TRIGfxInfo.isFilled = true;
	else
	TRIGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TRIGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TRIGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTRIAction::Execute() 
{
	if (pManager->getvoice())
	{
		sndPlaySound(TEXT("sounds\\triangle.wav"), SND_FILENAME | SND_ASYNC);
	}
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CTriangle *t=new CTriangle(P1, P2,P3, TRIGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(t);
}

