#pragma once
#include "ApplicationManager.h"
#include"Actions\Action.h"
#include"GUI\Input.h"
#include"GUI\Output.h"
#include "Figures\CRectangle.h"
#include "Figures\line.h"
#include "Figures\Rhombus.h"
#include "Figures\Triangle.h"
#include "Figures\Ellipse.h"
#include"Triangle.h"
class Cut:public Action
{CFigure*s;
CFigure*c;
GfxInfo g;
CRectangle *r;
CLine *l;
CTriangle*t;
CRhombus*ro;
CEllipse*e; 

public:
	Cut(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~Cut();
};

