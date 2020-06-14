#include "selectaction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

selectaction::selectaction(ApplicationManager * pApp) :Action(pApp)
{}

void selectaction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
}

//Execute the action
void selectaction::Execute()
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

