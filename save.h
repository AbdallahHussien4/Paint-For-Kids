#pragma once
#include <fstream>
#include "Actions\Action.h"
class save :
	public Action
{
protected:
	string fileName;
	
public:
	save(ApplicationManager * pApp);
	 void ReadActionParameters();
	 void Execute() ;
	
	~save();
};




