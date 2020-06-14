#ifndef CFIGURE_H
#define CFIGURE_H
#include<fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.
	static int Id;

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	GfxInfo getg();
	void setg(GfxInfo g);
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
    void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual bool GetFigure (int x , int y);
	color getcolor();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	color convertToColour(string c);

	///Decide the parameters that you should pass to each function	
	void setID(int n);
	 virtual string getFigureType()=0;
	virtual void Save(ofstream &) = 0;	//Save the figure parameters to the file       /////////////////////////////////////
	
	virtual void Load(ifstream &Infile) = 0;

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	void setid (int);
	int getid ();
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif