#include "PickByColor.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include <cstdlib>
//#include <stdio.h>
//#include <stdlib.h>
#include "Triangle.h"



PickByColor::PickByColor(ApplicationManager * pApp):Action(pApp)
{
}
void PickByColor::Execute() {
	pManager->recopyfiglist();
	pManager->UpdateInterface();

	int rightcount = 0;           //number of right picks
	int wrongcount = 0;                  //number of wrong picks
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int NumberOfDrawnColors[5];           //each index has the count of the colored drawn shapes 
	pManager->GetNumberOfEachColor(NumberOfDrawnColors);
	int colornum;     //index


	// choose a color randomly
	do {
		colornum = (rand() % 5);

	} while (NumberOfDrawnColors[colornum] == 0);


	if (colornum == 0)
	{
		pOut->PrintMessage("pick all the shapes with red draw color ");
	}
	else if (colornum == 1)
	{
		pOut->PrintMessage("pick all the shapes with green draw color ");
	}
	else if (colornum == 2)
	{
		pOut->PrintMessage("pick all the shapes with white draw color");
	}
	else if (colornum == 3)
	{
		pOut->PrintMessage("pick all the shapes with black draw color");
	}
	else
	{
		pOut->PrintMessage("pick all the shapes with blue draw color");
	}
	do {
		pIn->GetPointClicked(P.x, P.y);
		CFigure* shape = pManager->GetFigure(P.x, P.y);
		if (shape != NULL)
		{
			if (colornum == 0)
				if (shape->getcolor() == RED) {
					NumberOfDrawnColors[colornum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;

			else if (colornum == 1) {
				if (shape->getcolor() == GREEN) {
					NumberOfDrawnColors[colornum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}

			else if (colornum == 2) {
				if (shape->getcolor() == WHITE) {
					NumberOfDrawnColors[colornum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}

			else if (colornum == 3) {
				if (shape->getcolor() == BLACK) {
					NumberOfDrawnColors[colornum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}

			else if (colornum == 4) {
				if (shape->getcolor() == BLUE) {
					NumberOfDrawnColors[colornum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}

		}
		//if the user clicked on the toolbar it exists the loop
		else if (P.y >= 0 && P.y < UI.ToolBarHeight)
			NumberOfDrawnColors[colornum] = 0;

	}
	while (NumberOfDrawnColors[colornum] != 0);
	
	if (NumberOfDrawnColors[colornum] == 0) {
		std::string s1 = std::to_string(wrongcount);
		std::string s2 = std::to_string(rightcount);
		pOut->PrintMessage("the wrong picks = " + s1 + "   the right picks =  " + s2);
	}

}





