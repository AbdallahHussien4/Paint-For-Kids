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
//#include"Line.h"
class Paste:public Action
{CFigure*s;
Point P;
GfxInfo g;
CRectangle *r;
CTriangle *t;
CLine *L;
bool b;
public:
	Paste(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~Paste();
};

