#include "AddEllipseAction.h"
#include "Ellipse.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp):Action(pApp)
{}

void AddEllipseAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the center");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	while (P1.y - 50 < 50 || P1.y + 50 > 600 || P1.x - 30 < 0 || P1.x + 30 > 1250)

	{
		pOut->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar, Choose a Valid Point");
		pIn->GetPointClicked(P1.x, P1.y);
	}
	if (pManager->getcolored()==true)
		EllipseGfxInfo.isFilled = true;
	else
	EllipseGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute() 
{
	if (pManager->getvoice())
	{
		sndPlaySound(TEXT("sounds\\ellipse.wav"), SND_FILENAME | SND_ASYNC);
	}
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a Ellipse with the parameters read from the user
	CEllipse *E=new CEllipse(P1, EllipseGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->AddFigure(E);
}

