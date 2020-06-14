#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* C;
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	bool colored;
	CFigure* p;
	bool IsCut;
	bool voice;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	GfxInfo G;
	CFigure* FigListCopy[200];
	int FigListCopyCount;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	void setsel(CFigure*c);
	CFigure* getsel();
	CFigure* getSelectedFig() const;
	CFigure* getClipboard() const;
	void setClipboard(CFigure*);
	void setIsCut(bool b);
	bool getIsCut();
	void setvoice(bool);
	bool getvoice();
	void setG(GfxInfo);
	GfxInfo getG();
	void unselect();
	void SendToBack();
	void SendToFront();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void deletec();
	void setCut(CFigure*);
	CFigure* getCut();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ;//Search for a figure given a point inside the figure 
	void deletesh(); //deletes a shape
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	int getfigcount ();
	void setcolored (bool);
	bool getcolored ();
	string convertToString(color c);
	color convertToColour(string c);
	void saveAll(ofstream &out);
	void savebytype(ofstream &Out, string );
	void loadFig();
	// -- The play Mode Functions
	
	void GetNumberOfEachChape(int *arr);
	void GetNumberOfEachColor(int *arr);
	void copyfiglist();   //takes a copy form the figlist before any changes
	void recopyfiglist();   //restores the original shapes drawn before any changes 


};

#endif