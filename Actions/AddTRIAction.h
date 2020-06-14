#pragma once
#include "Actions\Action.h"

//Add Triangle Action class
class AddTRIAction: public Action
{
private:
	Point P1, P2,P3; //Rectangle Corners
	GfxInfo TRIGfxInfo;
public:
	AddTRIAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();
	
	//Add triangle to the ApplicationManager
	virtual void Execute() ;
	
};

