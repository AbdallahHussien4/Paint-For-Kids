#pragma once
#include "Actions\Action.h"

class switchtodraw:public Action
{
public:
	switchtodraw(ApplicationManager *pApp);
	virtual void ReadActionParameters() {};
	virtual void Execute();
	~switchtodraw() {};
};

