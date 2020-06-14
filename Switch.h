#pragma once
#include "Actions\Action.h"
class Switch:public Action
{

public:
	Switch (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

