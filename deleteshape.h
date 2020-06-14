#pragma once
#include"Actions/Action.h"
class deleteshape:public Action
{
public:
	deleteshape(ApplicationManager * pApp);
	virtual void ReadActionParameters() {};
	virtual void Execute();
	~deleteshape() {};
};

