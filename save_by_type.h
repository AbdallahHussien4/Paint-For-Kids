#pragma once
#include <fstream>
#include "Actions\Action.h"
class save_by_type :
	public Action 
{
protected:
	string fileName1 , type;
public:
	
	save_by_type(ApplicationManager * pApp);
	 void ReadActionParameters();
	 void Execute() ;
	~save_by_type();
};

