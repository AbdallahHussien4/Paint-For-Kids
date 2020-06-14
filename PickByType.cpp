#include "PickByType.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include <cstdlib>
#include "Triangle.h"



PickByType::PickByType(ApplicationManager * pApp) :Action(pApp)
{
	
}
void PickByType::Execute() {
	pManager->recopyfiglist();         // to restor the original graph
	pManager->UpdateInterface();



	int rightcount = 0;           //number of right picks
	int wrongcount = 0;                  //number of wrong picks
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int NumberOfDrawnShapes[5];           //each index has the count of a drawn shape EX:NumberOfDrawnShapes[0] is the number of rectangles
	pManager->GetNumberOfEachChape(NumberOfDrawnShapes);
	int shapenum;     //index


	// choose a shape randomly
	do {
	shapenum = (rand() % 5) ;
		
	} while (NumberOfDrawnShapes[shapenum] == 0 );


	if (shapenum == 0)
	{
		pOut->PrintMessage("pick all the rectangles ");
	}
	else if(shapenum==1)
	{pOut->PrintMessage("pick all the lines ");
	}
	else if (shapenum == 2)
	{pOut->PrintMessage("pick all the triangles "); 
}
	else if (shapenum == 3)
	{pOut->PrintMessage("pick all the rhombuses ");
	}
	else
		{pOut->PrintMessage("pick all the ellipses"); 
	}





	//the next code takes a click and checks if it on the right shape the right count increases else the wrong count increases
	do {
		pIn->GetPointClicked(P.x, P.y);
		CFigure* shape = pManager->GetFigure(P.x, P.y);
		if (shape != NULL)
		{
			if (shapenum == 0)
			{
				CRectangle*cp = dynamic_cast<CRectangle*>(shape);
				if (cp != NULL) {
					NumberOfDrawnShapes[shapenum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}
			else if (shapenum == 1) {
				CLine*cp = dynamic_cast<CLine*>(shape);
				if (cp != NULL) {
					NumberOfDrawnShapes[shapenum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}
			else if (shapenum == 2) {
				CTriangle *tp = dynamic_cast<CTriangle*>(shape);
				if (tp != NULL) {
					NumberOfDrawnShapes[shapenum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}
			else if (shapenum == 3) {
				CRhombus*cp = dynamic_cast<CRhombus*>(shape);
				if (cp != NULL) {
					NumberOfDrawnShapes[shapenum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}
			else if (shapenum == 4) {
				CEllipse*cp = dynamic_cast<CEllipse*>(shape);
				if (cp != NULL) {
					NumberOfDrawnShapes[shapenum]--; pManager->deletesh(); pManager->UpdateInterface(); rightcount++;
				}
				else wrongcount++;
			}

		}
		//if the user clicked on the toolbar it exists the loop
		else if (P.y >= 0 && P.y < UI.ToolBarHeight) 
				NumberOfDrawnShapes[shapenum] = 0;
		
	} while (NumberOfDrawnShapes[shapenum] != 0);

	if (NumberOfDrawnShapes[shapenum] == 0) {
		std::string s1 = std::to_string(wrongcount);
		std::string s2 = std::to_string(rightcount);
		pOut->PrintMessage("the wrong picks = "+ s1+"   the right picks =  "+s2);
	}


}


