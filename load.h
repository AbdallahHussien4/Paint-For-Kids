#pragma once
#include <fstream>
#include "Actions\Action.h"
class load :
	public Action
{
	string fileName ;
public:
	load(ApplicationManager * pApp);
	 void ReadActionParameters();
	 void Execute() ;
	~load();
};

