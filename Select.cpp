#include "Select.h"

#include "Figures\CRectangle.h"
#include "Figures\line.h"
#include "Figures\Rhombus.h"
#include "Figures\Triangle.h"
#include "Figures\Ellipse.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

Select:: Select (ApplicationManager * pApp):Action(pApp)
{}

void Select::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
}

//Execute the action
void Select::Execute() 
{
	//This action needs to read some parameters first
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
	CFigure * f;
	f = pManager->getsel();
	CFigure*test = NULL;

	CFigure* temp;
	temp = pManager->GetFigure(P.x, P.y);
	bool test1 = true;
	if (temp != NULL)
	{

		temp->SetSelected(true);
		temp->PrintInfo(pOut);
		test = temp;
		if (f == test && f != NULL && test != NULL && temp != NULL)
		{
			temp->SetSelected(false);
			pOut->PrintMessage("you unselect this figure");
			pManager->unselect();
			f = NULL;
			pManager->setsel(f);
		}
		else {
			pManager->setsel(temp);
		}
	}
	else
		pOut->ClearStatusBar();
	
}
