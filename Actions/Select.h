#pragma once
#include "Action.h"
class Select
{
	Point p;
public:
	//Reads parameters
	virtual void ReadActionParameters();
	
	//Add to the ApplicationManager
	virtual void Execute() ;
};

