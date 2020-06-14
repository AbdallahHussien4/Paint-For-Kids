#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLORS
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_LINE,
	ITM_TRI,
	ITM_RHOMBUS,
	ITM_ELLIPSE,
	ITM_SELECT,
	ITM_CHNG_DRAW_CLR,
	ITM_CHNG_FILL_CLR,
	ITM_DEL,
	ITM_SAVE,
	ITM_SAVE_BY_TYPE,
	ITM_LOAD,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_quarter,
	ITM_half,
	ITM_double,
	ITM_4times,
	ITM_voice,
	ITM_back,
	ITM_front,

	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	ITM_TOPLAY,
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_TODRAW,
	ITM_FIGURETYPE1,
	ITM_FIGURECOLOR1,
	ITM_EXITPLAYMODE,
	ITM_EMPTY,
	ITM_EMPTY1,
	ITM_EMPTY2,
	ITM_EMPTY3,
	ITM_EMPTY4,
	ITM_EMPTY5,
	ITM_EMPTY6,
	ITM_EMPTY7,
	ITM_EMPTY8,
	ITM_EMPTY9,
	ITM_EMPTY10,
	ITM_EMPTY11,
	ITM_EMPTY12,
	ITM_EMPTY13,
	ITM_EMPTY14,
	ITM_EMPTY15,
	ITM_EMPTY16,
	ITM_EMPTY17,
	ITM_EMPTY18,
	ITM_EMPTY19,
	ITM_EMPTY20,
	ITM_EMPTY21,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

}; 
 enum ColorMenuItems
 {
	 ITM_RED,
	ITM_GREEN,
	ITM_WHITE,
	ITM_BLACK,
	ITM_BLUE,
	ITM_EMPTY22,
	ITM_EMPTY23,
	ITM_EMPTY24,
	ITM_EMPTY25,
	ITM_EMPTY26,
	ITM_EMPTY27,
	ITM_EMPTY28,
	ITM_EMPTY29,
	ITM_EMPTY30,
	ITM_EMPTY31,
	ITM_EMPTY32,
	ITM_EMPTY33,
	ITM_EMPTY34,
	ITM_EMPTY35,
	ITM_EMPTY36,
	ITM_EMPTY37,
	ITM_EMPTY38,
	ITM_EMPTY39,
	ITM_EMPTY40,
	ITM_EMPTY41,
	ITM_EMPTY42,
	
	
	Color_ITM_COUNT
 };

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	/// Add more members if needed

}UI;	//create a global object UI

#endif