#include"Copy.h"
Copy::Copy(ApplicationManager * pApp):Action(pApp){
	c=NULL;
	s=NULL;
	
}
void Copy::ReadActionParameters(){
	s=pManager->getSelectedFig();
	
	if(pManager->getIsCut())
	{c=pManager->getCut();
	g=pManager->getG();
	c->setg(g);}
	 g=s->getg();
	pManager->setIsCut(false);
}

void Copy::Execute(){
	
	Input* pin=pManager->GetInput();
	Output*pout=pManager->GetOutput();
	if(pManager->getSelectedFig())
	{pout->PrintMessage("Copy");
	ReadActionParameters();
	if(dynamic_cast<CRectangle*>(s))
	{r=dynamic_cast<CRectangle*>(s);
	Point p1=r->getp1();
	Point p2=r->getp2();
	CRectangle*R=new CRectangle(p1,p2,g);
	pManager->setClipboard(R);
	}
	else if(dynamic_cast<CLine*>(s))
	{l=dynamic_cast<CLine*>(s);
	Point p1=l->getp1();
	Point p2=l->getp2();
	CLine *L=new CLine(p1,p2,g);
	pManager->setClipboard(L);
	}
	else if(dynamic_cast<CTriangle*>(s))
	{t=dynamic_cast<CTriangle*>(s);
	Point p1=t->getp1();
	Point p2=t->getp2();
	Point p3=t->getp3();
	CTriangle*T=new CTriangle(p1,p2,p3,g);
	pManager->setClipboard(T);
	}
	else if(dynamic_cast<CRhombus*>(s))
	{ro=dynamic_cast<CRhombus*>(s);
	Point p=ro->getp();
	CRhombus*RO=new CRhombus(p,g);
	pManager->setClipboard(RO);}
	else if(dynamic_cast<CEllipse*>(s))
	{e=dynamic_cast<CEllipse*>(s);
	Point p=e->getp();
	CEllipse*E=new CEllipse(p,g);
	pManager->setClipboard(E);
	}
	
	}
	else pout->PrintMessage("No selected sahpe");
}
Copy::~Copy(){
	
}