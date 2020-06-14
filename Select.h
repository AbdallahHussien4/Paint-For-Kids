#pragma once
#include "Actions\Action.h"
class Select:public Action
{
	Point P;
public:
	//Reads parameters
	Select (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	
	//Add to the ApplicationManager
	virtual void Execute() ;
	~Select ();
};

