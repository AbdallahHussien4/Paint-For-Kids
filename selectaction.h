#pragma once
#include "Figures\CRectangle.h"
#include "Figures\line.h"
#include "Figures\Rhombus.h"
#include "Figures\Triangle.h"
#include "Figures\Ellipse.h"
#include "Actions\Action.h"
class selectaction:public Action
{
	Point P;
public:
	selectaction (ApplicationManager * pApp);
	virtual void ReadActionParameters();
	
	//Add to the ApplicationManager
	virtual void Execute() ;
};

