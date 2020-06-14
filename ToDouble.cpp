#include "ToDouble.h"


ToDouble::ToDouble(ApplicationManager * pApp):Action(pApp)
{
}
void ToDouble::ReadActionParameters(){
	
	s=pManager->getSelectedFig();
	
}
void ToDouble::Execute() {
	Input* pin=pManager->GetInput();
	Output*pout=pManager->GetOutput();
	ReadActionParameters();
	if(s){
	if(dynamic_cast<CRectangle*>(s))
	{

		r=dynamic_cast<CRectangle*>(s);
		pout->PrintMessage("Resize to double ");
	
	 Point p1 =r->getp1();
	 Point p2=r->getp2();
	 Point p3;
	 p3.x=(p1.x+p2.x)/2;
	 p3.y=(p1.y+p2.y)/2;
	p1.x=2*p1.x-p3.x;
	p1.y=2*p1.y-p3.y;
	p2.x=p2.x*2-p3.x;
	p2.y=p2.y*2-p3.y;
	if (p1.y < 50 || p2.y < 50 || p1.y>600 || p2.y>600||p1.x<0||p2.x<0||p1.x>1250||p2.x>1250)
	
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , Choose another shape");
	else{
	r->setp1(p1);
	r->setp2(p2);
	pManager->UpdateInterface();
	
	}}
	else if(dynamic_cast<CLine*>(s))
	{

		l=dynamic_cast<CLine*>(s);
		pout->PrintMessage("Resize to double ");
	
		Point p1 =l->getp1();
		Point p2=l->getp2();
	 Point p3;
	 p3.x=(p1.x+p2.x)/2;
	 p3.y=(p1.y+p2.y)/2;
	p1.x=2*p1.x-p3.x;
	p1.y=2*p1.y-p3.y;
	p2.x=p2.x*2-p3.x;
	p2.y=p2.y*2-p3.y;
	if (p1.y < 50 || p2.y < 50 || p1.y>600 || p2.y>600||p1.x<0||p2.x<0||p1.x>1250||p2.x>1250)
	
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , Choose another shape");
	else{
	l->setp1(p1);
	l->setp2(p2);
	pManager->UpdateInterface();
	
	}}
	else if(dynamic_cast<CTriangle*>(s))
	{

		t=dynamic_cast<CTriangle*>(s);
		pout->PrintMessage("Resize to double ");
	
		Point p1 =t->getp1();
		Point p2=t->getp2();
		Point p4=t->getp3();
	 Point p3;
	 p3.x=(p1.x+p2.x+p4.x)/3;
	 p3.y=(p1.y+p2.y+p4.y)/3;
	p1.x=2*p1.x-p3.x;
	p1.y=2*p1.y-p3.y;
	p2.x=p2.x*2-p3.x;
	p2.y=p2.y*2-p3.y;
	p4.x=2*p4.x-p3.x;
	p4.y=p4.y*2-p3.y;
	if(p1.y < 50 || p2.y < 50 || p3.y < 50 || p1.y>600 || p2.y>600 || p3.y>600||p1.x<0||p2.x<0||p3.x<0||p1.x>1250||p2.x>1250||p3.x>1250)
	
		pout->PrintMessage("You Can't Draw On The Tool Bar Or The Status Bar , Choose another shape");
	else{
	t->setp1(p1);
	t->setp2(p2);
	t->setp3(p4);
	pManager->UpdateInterface();
	
	}}
	
	}else pout->PrintMessage("No selected shape !!");
}


ToDouble::~ToDouble(void)
{
}
