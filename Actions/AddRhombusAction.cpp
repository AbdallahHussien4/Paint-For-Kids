#include "AddRhombusAction.h"

#include "Rhombus.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRhombusAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at the center");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RHOMGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RHOMGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RHOMGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombusAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a Rhombus with the parameters read from the user
	CRhombus *Rh=new CRhombus(P1, RHOMGfxInfo);

	//Add the Rhombus to the list of figures
	pManager->AddFigure(Rh);
}

