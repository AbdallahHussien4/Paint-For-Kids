#pragma once
#include "Actions/Action.h"
#include "Figures/Ellipse.h"
#include "Figures/CRectangle.h"
#include "Figures/Line.h"
#include "Figures/Rhombus.h"
#include "Figures/Triangle.h"

class PickByType:public Action
{
	Point P;
public:

	PickByType(ApplicationManager * pApp);
	virtual void ReadActionParameters() {};
	virtual void Execute();
	~PickByType() {};
};

