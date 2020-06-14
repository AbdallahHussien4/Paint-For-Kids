#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTRIAction.h"
#include "Actions\AddRhombusAction.h"
#include "Actions\AddEllipseAction.h"
#include "Select.h"
#include "Switch.h"
#include "PickByType.h"
#include"PickByColor.h"
#include "switchtodraw.h"
#include "deleteshape.h"
#include "changecolor.h"
#include "ChangeTheDrawColor.h"
#include "selectaction.h"
#include "save.h"
#include "save_by_type.h"
#include"load.h"
#include "Copy.h"
#include "Paste.h"
#include "Cut.h"
#include "ToHalf.h"
#include "ToDouble.h"
#include "ToQuarter.h"
#include "ToFour.h"
#include "Voice.h"
#include "ToFront.h"
#include "ToBack.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	Clipboard = NULL;
	SelectedFig = NULL;
	IsCut = false;
	voice = false;
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	SelectedFig=NULL;
	colored = false;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
        
		case DRAW_TRI:
			pAct = new AddTRIAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;

		case select1:
			pAct = new Select (this);
			pOut->PrintMessage("Select A Shape");
		    break;
			
		case TO_PLAY:
			pAct = new Switch (this);
			break;

		case TO_DRAW:
			pAct = new switchtodraw(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new changecolor (this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChangeTheDrawColor (this);
			break;

		case DRAWING_AREA:
			pAct = new selectaction (this);
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		case ITM_FIGURETYPE:
			pAct = new PickByType(this);
			break;

		case ITM_FIGURECOLOR:
			pAct = new PickByColor(this);
			break;

		case DEL:
			pAct = new deleteshape(this);
			break;

		case copy1:
			if (Clipboard)
			{
				delete Clipboard;
				Clipboard = NULL;
			}
			pAct = new Copy(this);
			break;
		case LOAD:
			pAct = new load (this);
			pOut->PrintMessage("LOADING Shapes");
			break;
		case SAVE:																			///////////////////////////////////
			pAct = new save (this);
			pOut->PrintMessage("Save Shapes");
			break;
		case SAVE_BY_TYPE:																			///////////////////////////////////
			pAct = new save_by_type (this);
			pOut->PrintMessage("Save type Shapes");
			break;
		case paste:
			pAct = new Paste(this);
			break;

		case cut:
			if (Clipboard)
			{
				delete Clipboard;
				Clipboard = NULL;
			}
			pAct = new Cut(this);
			break;
		case half:
			pAct = new ToHalf(this);
			break;
		case time2:
			pAct = new ToDouble(this);
			break;

		case quarter:
			pAct = new ToQuarter(this);
			break;
		case time4:
			pAct = new ToFour(this);
			break;
		case vooice:
			pAct = new Voice(this);
			break;
		case front:
			pAct=new ToFront(this);
			break;
		case back:
			pAct=new ToBack(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
void ApplicationManager::unselect() { SelectedFig = NULL; }

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )

		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
	if (y < 50 || y < 50 || y>600 || y>600)
	{
	return NULL;
	}
	else
	{
	for (int i=FigCount-1;i>=0;i--)
		{if(FigList[i]->GetFigure(x,y))
			{SelectedFig=FigList[i];
	for (int i =1 ; i<=FigCount ; i++)
	FigList[i-1]->setid(i);//(i-1)to count the figures in acorrect way from the first one

	       for(int i=FigCount-1 ; i>=0 ;i--)
		   { 
			   FigList[i]->SetSelected(false);
		   }
		   return SelectedFig;}

}

	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i=FigCount-1 ; i>=0 ; i--)
	{
		FigList[i]->SetSelected(false);
		SelectedFig =NULL;
	}
	
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	return NULL;
	}}
void ApplicationManager::deletesh() {
	for (int i = 0; i < FigCount; i++) {
		if (SelectedFig == FigList[i]) {
			for (int j = i; j < FigCount - 1; j++) {
				FigList[j] = FigList[j+1];
			}
			FigList[FigCount - 1] = NULL;
			SelectedFig = NULL;
			FigCount--;
			break;
		}
	}
}
void ApplicationManager:: SendToFront(){
	CFigure*s;
	for (int i = 0; i < FigCount; i++) {
		if (SelectedFig == FigList[i]) {
			s=FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = s;
			UpdateInterface();
			
		}
	}
}



void ApplicationManager:: SendToBack(){
		CFigure*s;
	for (int i = 0; i < FigCount; i++) {
		if (SelectedFig == FigList[i]) {
			s=FigList[i];
			FigList[i] = FigList[0];
			FigList[0] = s;
			UpdateInterface();
			
		}
	}
}

void ApplicationManager::deletec() {
	for (int i = 0; i < FigCount; i++) {
		if (p == FigList[i]) {
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			break;
		}
	}
}
void ApplicationManager:: saveAll(ofstream &out){
	out << FigCount <<endl ;
	for (int i=FigCount-1 ; i>=0 ; i--)
	{
		FigList[i]->SetSelected(false);
	}
	for (int i=FigCount-1 ; i>=0 ; i--)
	{
		FigList[i]->Save(out);
	}


}
void ApplicationManager:: loadFig(){

	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = NULL;
	}
	FigCount = 0; C->setID(0);
}


void ApplicationManager::savebytype(ofstream &Out, string type)
{
	int typecount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->getFigureType() == type)
			typecount++;
	}
	Out << typecount <<"\n";
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->getFigureType() == type)
			FigList[i]->Save(Out);
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
void ApplicationManager::setsel(CFigure*c){SelectedFig=c;}
CFigure* ApplicationManager :: getsel () 
{
return SelectedFig;

}
int ApplicationManager::getfigcount ()
{return FigCount;}
bool ApplicationManager:: getcolored ()
{
return colored;
}
void ApplicationManager::setcolored (bool t)
{colored = t;}
CFigure* ApplicationManager::getSelectedFig() const {
	return SelectedFig;
}
CFigure* ApplicationManager::getClipboard() const {
	return Clipboard;
}
void ApplicationManager::setClipboard(CFigure* selected) {
	Clipboard = selected;
}
void ApplicationManager::setIsCut(bool b) {
	IsCut = b;
}
bool ApplicationManager::getIsCut() {
	return IsCut;
}
void ApplicationManager::setG(GfxInfo g) {
	G = g;
}
GfxInfo ApplicationManager::getG() {
	return G;
}
void ApplicationManager::setCut(CFigure*s) {
	p = s;
}
CFigure* ApplicationManager::getCut() {
	return p;
}
void ApplicationManager::setvoice(bool v) {
	voice = v;
}
bool ApplicationManager::getvoice() {
	return voice;
}
string  ApplicationManager:: convertToString(color c){              
	
	if(c == RED )
		return "Red";
	else if(c == WHITE )
		return "WHITE";
	else if(c == BLACK )
		return "BLACK";
	else if(c == GREEN )
		return "GREEN";
	else if(c == MAGENTA )
		return "MAGENTA";
	else if(c == TURQUOISE )
		return "TURQUOISE";
	return "NonFill";
}
color ApplicationManager:: convertToColour(string c){

	if (c == "Red")
		return RED;
	else if (c == "WHITE")
		return WHITE;
	else if (c == "BLACK")
		return BLACK;
	else if (c == "GREEN")
		return GREEN;
	else if (c == "MAGENTA")
		return MAGENTA;
	else if (c == "TURQUOISE")
		return TURQUOISE;
	else if (c == "NonFill")
		return GRAY ;
}
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
//==================================================================================//
//							The Draw Mode Functions         						//
//==================================================================================//

void ApplicationManager::GetNumberOfEachChape(int *arr) {

	for (int i = 0; i < 5; i++)arr[i] = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CRectangle*cp = dynamic_cast<CRectangle*>(FigList[i]);
		if (cp != NULL)arr[0]++;
		else
		{
			CLine*lp = dynamic_cast<CLine*>(FigList[i]);
			if (lp != NULL)arr[1]++;
			else
			{
				CRhombus*rp = dynamic_cast<CRhombus*>(FigList[i]);
				if (rp != NULL)arr[3]++;
				else
				{
					CEllipse*ep = dynamic_cast<CEllipse*>(FigList[i]);
					if (ep != NULL)arr[4]++;
					else arr[2]++;
				}
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::GetNumberOfEachColor(int *arr) {

	for (int i = 0; i < 5; i++)arr[i] = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getcolor() == RED)arr[0]++;
		else if (FigList[i]->getcolor() == GREEN)arr[1]++;
		else if (FigList[i]->getcolor() == WHITE)arr[2]++;
		else if (FigList[i]->getcolor() == BLACK)arr[3]++;
		else arr[4]++;

	}
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::copyfiglist() {
	FigListCopyCount = FigCount;
	for (int i = 0; i < FigCount; i++)
		FigListCopy[i] = FigList[i];

}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::recopyfiglist() {
	FigCount = FigListCopyCount;
	for (int i = 0; i < FigCount; i++)
		FigList[i] = FigListCopy[i];
	UpdateInterface();
}