#pragma once
#include "Actions\Action.h"
class ChangeTheDrawColor : public Action
{
	Point p;

public:
	ChangeTheDrawColor (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	//void ChngDrawClr(color Dclr);
};

