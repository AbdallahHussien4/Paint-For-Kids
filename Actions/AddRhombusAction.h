#pragma once
#include "Actions\Action.h"

//Add Rhombus Action class
class AddRhombusAction: public Action
{
private:
	Point P1; //Rhombus center
	GfxInfo RHOMGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads Rhombus parameters
	virtual void ReadActionParameters();
	
	//Add Rhombus to the ApplicationManager
	virtual void Execute() ;
	
};


