#include "Paste.h"


Point operator*(float x,Point p){
	p.x=x*p.x;
	p.y=x*p.y;
return p;}
Point operator-(Point p1,Point p2){
	Point p3;
	p3.x=p1.x-p2.x;
	p3.y=p1.y-p2.y;
return p3;}
Point operator +(Point p1,Point p2){
	Point p3;
	p3.x=p1.x+p2.x;
	p3.y=p1.y+p2.y;
	return p3;}
Point operator /(Point p1,float x){
	
	p1.x=p1.x/x;
	p1.y=p1.y/x;
	return p1;}

Paste::Paste(ApplicationManager * pApp):Action(pApp){

	
}
void Paste::ReadActionParameters(){
	b=pManager->getIsCut();
	s=pManager->getClipboard();
	g=s->getg();
}

void Paste::Execute(){
	
	Input* pin=pManager->GetInput();
	Output*pout=pManager->GetOutput();
	if(pManager->getClipboard())
	{ReadActionParameters();
	if(b){
	if(dynamic_cast<CRectangle*>(s))
	{

		r=dynamic_cast<CRectangle*>(s);
		pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	 Point p1 =r->getp1();
	 Point p2=r->getp2();
	 Point p3=(p1+p2)/2;
	 int x=p3.x-P.x;
	 int y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	while (p1.y < 50 || p2.y < 50 || p1.y>600 || p2.y>600||p1.x<0||p2.x<0||p1.x>1250||p2.x>1250)
	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , click a new point");
		pin->GetPointClicked(P.x, P.y);
	p1 =r->getp1();
	 p2=r->getp2();
	 p3=(p1+p2)/2;
	 x=p3.x-P.x;
	 y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;}
	
	CRectangle*R=new CRectangle(p1,p2,g);
	
		pManager->AddFigure(R);
		pManager->deletec();
		pManager->setsel(NULL);
		pManager->setIsCut(false);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else
		if(dynamic_cast<CEllipse*>(s))
	{
	pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	while (P.y - 50 < 50 || P.y + 50 > 600 || P.x - 30 < 0 || P.x + 30 > 1250)

	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar, Choose a Valid Point");
		pin->GetPointClicked(P.x, P.y);
	}
	CEllipse*E=new CEllipse(P,g);
	pManager->AddFigure(E);
	pManager->deletec();
	pManager->setIsCut(false);
	pManager->setsel(NULL);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else 
		if(dynamic_cast<CRhombus*>(s))
	{pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	while (P.y - 70 < 50 || P.y + 70 > 600 || P.x - 40 < 0 || P.x + 40 > 1250)

	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar, Choose a Valid Point");
		pin->GetPointClicked(P.x, P.y);
	}
		
		CRhombus*R=new CRhombus(P,g);
	pManager->AddFigure(R);
	pManager->deletec();
	pManager->setIsCut(false);
	pManager->setsel(NULL);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else
		if(dynamic_cast< CTriangle *>(s))
	{
		t=dynamic_cast<CTriangle*>(s);
		pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	Point p1=t->getp1();
	Point p2=t->getp2();
	Point p3=t->getp3();
	Point p4=(p1+p2+p3)/3;
	int x=p4.x-P.x;
	int y=p4.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	p3.x=p3.x-x;
	p3.y=p3.y-y;
	while (p1.y < 50 || p2.y < 50 || p3.y < 50 || p1.y>600 || p2.y>600 || p3.y>600||p1.x<0||p2.x<0||p3.x<0||p1.x>1250||p2.x>1250||p3.x>1250)
	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , click a new point ");
		pin->GetPointClicked(P.x,P.y);
	p1=t->getp1();
	p2=t->getp2();
	p3=t->getp3();
	p4=(p1+p2+p3)/3;
	x=p4.x-P.x;
	y=p4.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	p3.x=p3.x-x;
	p3.y=p3.y-y;
	}
	CTriangle*T=new CTriangle(p1,p2,p3,g);
		pManager->AddFigure(T);
		pManager->deletec();
		pManager->setIsCut(false);
		pManager->setsel(NULL);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else
		if(dynamic_cast<CLine *>(s))
	{
		L=dynamic_cast<CLine*>(s);
		pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	Point p1=L->getp1();
	Point p2=L->getp2();
	Point p3=(p1+p2)/2;
	int x=p3.x-P.x;
	int y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	while (p1.y < 50 || p2.y < 50 || p1.y>600 || p2.y>600||p1.x<0||p2.x<0||p1.x>1250||p2.x>1250)
	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar ,click a new points");
		pin->GetPointClicked(P.x, P.y);
	p1=L->getp1();
	p2=L->getp2();
	p3=(p1+p2)/2;
	x=p3.x-P.x;
	y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	}
	CLine*l=new CLine(p1,p2,g);
		pManager->AddFigure(l);
		pManager->deletec();
		pManager->setIsCut(false);
		pManager->setsel(NULL);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}
}
else if(dynamic_cast<CRectangle*>(s))
	{

		r=dynamic_cast<CRectangle*>(s);
		pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	 Point p1 =r->getp1();
	 Point p2=r->getp2();
	 Point p3=(p1+p2)/2;
	 int x=p3.x-P.x;
	 int y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	while (p1.y < 50 || p2.y < 50 || p1.y>600 || p2.y>600||p1.x<0||p2.x<0||p1.x>1250||p2.x>1250)
	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , click a new point");
		pin->GetPointClicked(P.x, P.y);
	p1 =r->getp1();
	 p2=r->getp2();
	 p3=(p1+p2)/2;
	 x=p3.x-P.x;
	 y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;}
	
	CRectangle*R=new CRectangle(p1,p2,g);
	
		pManager->AddFigure(R);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else
		if(dynamic_cast<CEllipse*>(s))
	{
	pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	while (P.y - 50 < 50 || P.y + 50 > 600 || P.x - 30 < 0 || P.x + 30 > 1250)

	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar, Choose a Valid Point");
		pin->GetPointClicked(P.x, P.y);
	}
	CEllipse*E=new CEllipse(P,g);
	pManager->AddFigure(E);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else 
		if(dynamic_cast<CRhombus*>(s))
	{pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	while (P.y - 70 < 50 || P.y + 70 > 600 || P.x - 40 < 0 || P.x + 40 > 1250)

	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar, Choose a Valid Point");
		pin->GetPointClicked(P.x, P.y);
	}
		
		CRhombus*R=new CRhombus(P,g);
	pManager->AddFigure(R);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else
		if(dynamic_cast< CTriangle *>(s))
	{
		t=dynamic_cast<CTriangle*>(s);
		pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	Point p1=t->getp1();
	Point p2=t->getp2();
	Point p3=t->getp3();
	Point p4=(p1+p2+p3)/3;
	int x=p4.x-P.x;
	int y=p4.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	p3.x=p3.x-x;
	p3.y=p3.y-y;
	while (p1.y < 50 || p2.y < 50 || p3.y < 50 || p1.y>600 || p2.y>600 || p3.y>600||p1.x<0||p2.x<0||p3.x<0||p1.x>1250||p2.x>1250||p3.x>1250)
	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , click a new point ");
		pin->GetPointClicked(P.x,P.y);
	p1=t->getp1();
	p2=t->getp2();
	p3=t->getp3();
	p4=(p1+p2+p3)/3;
	x=p4.x-P.x;
	y=p4.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	p3.x=p3.x-x;
	p3.y=p3.y-y;
	}
	CTriangle*T=new CTriangle(p1,p2,p3,g);
		pManager->AddFigure(T);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}


	else
		if(dynamic_cast<CLine *>(s))
	{
		L=dynamic_cast<CLine*>(s);
		pout->PrintMessage("Paste,Click A Point :");
	pin->GetPointClicked(P.x,P.y);
	Point p1=L->getp1();
	Point p2=L->getp2();
	Point p3=(p1+p2)/2;
	int x=p3.x-P.x;
	int y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	while (p1.y < 50 || p2.y < 50 || p1.y>600 || p2.y>600||p1.x<0||p2.x<0||p1.x>1250||p2.x>1250)
	{
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar ,click a new points");
		pin->GetPointClicked(P.x, P.y);
	p1=L->getp1();
	p2=L->getp2();
	p3=(p1+p2)/2;
	x=p3.x-P.x;
	y=p3.y-P.y;
	p1.x=p1.x-x;
	p1.y=p1.y-y;
	p2.x=p2.x-x;
	p2.y=p2.y-y;
	}
	CLine*l=new CLine(p1,p2,g);
		pManager->AddFigure(l);
	pManager->UpdateInterface();
	pout->ClearStatusBar();
	}
}else pout->PrintMessage("No copied or cutted shape");
	}



Paste::~Paste(void)
{
}
