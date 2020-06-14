#include "selectaction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

selectaction:: selectaction (ApplicationManager * pApp):Action(pApp)
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
	/*bool test = true;
	CFigure * f;*/
	CFigure* temp;
	temp=pManager ->GetFigure(P.x ,P.y);

	if(temp!=NULL)
	{	
	/*f=pManager ->GetFigure(P.x ,P.y);
		if(f == temp)
		{
			f->SetSelected(false);
			 f =NULL;
		}*/
	    temp->SetSelected(true);
		temp->PrintInfo(pOut);
	}
	else 
	pOut->ClearStatusBar();
	pManager->setsel(temp);
}

