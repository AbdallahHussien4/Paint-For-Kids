#include "Select.h"


void Select::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();

}

//Execute the action
void Select::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	
	//Add the rectangle to the list of figures
	pManager->GetFigure(R);
}
