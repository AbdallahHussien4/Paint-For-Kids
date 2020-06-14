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

class ToDouble:public Action
{CFigure*s;
GfxInfo g;
CRectangle *r;
CTriangle *t;
CLine *l;
public:
	ToDouble(ApplicationManager * pApp);
	virtual void ReadActionParameters() ;
	virtual void Execute();
	~ToDouble(void);
};
