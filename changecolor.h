#pragma once
#include "Actions\Action.h"
class changecolor : public Action
{
public:
	changecolor (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	//void ChngFillClr(color Fclr);
};

