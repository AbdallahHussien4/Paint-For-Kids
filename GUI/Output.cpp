#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 4;
	UI.wy = 4;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = getCrntFillColor();	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rec.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhom.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Ellip.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Del.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_SAVE_BY_TYPE] = "images\\MenuItems\\save_by_type.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\Draw_Color.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\Fill_color.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Pickup.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_TOPLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_quarter] = "images\\MenuItems\\quarter.jpg";
	MenuItemImages[ITM_half] = "images\\MenuItems\\half.jpg";
	MenuItemImages[ITM_double] = "images\\MenuItems\\2.jpg";
	MenuItemImages[ITM_4times] = "images\\MenuItems\\4.jpg";
	MenuItemImages[ITM_voice] = "images\\MenuItems\\voice.jpg";
	MenuItemImages[ITM_front] = "images\\MenuItems\\front.jpg";
	MenuItemImages[ITM_back] = "images\\MenuItems\\back.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_TODRAW] = "images\\MenuItems\\Menu_drawmode.jpg";
	MenuItemImages[ITM_FIGURETYPE1] = "images\\MenuItems\\Menu_figuretype1.jpg";
	MenuItemImages[ITM_FIGURECOLOR1] = "images\\MenuItems\\Menu_fillcolor1.jpg";
	MenuItemImages[ITM_EXITPLAYMODE] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_EMPTY] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY1] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY2] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY3] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY4] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY5] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY6] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY7] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY8] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY9] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY10] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY11] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY12] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY13] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY14] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY15] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY16] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY17] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY18] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY19] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY20] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY21] = "images\\MenuItems\\EMPTY.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatColorToolBar() const
{
	UI.InterfaceMode = MODE_COLORS;

	
	string MenuItemImages[Color_ITM_COUNT];
	
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_EMPTY22] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY23] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY24] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY25] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY26] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY27] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY28] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY29] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY30] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY31] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY32] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY33] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY34] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY35] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY36] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY37] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY38] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY39] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY40] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY41] = "images\\MenuItems\\EMPTY.jpg";
	MenuItemImages[ITM_EMPTY42] = "images\\MenuItems\\EMPTY.jpg";
	
	
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < Color_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TRIGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TRIGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TRIGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TRIGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::DrawRHOM(Point P1, GfxInfo RHOMGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RHOMGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RHOMGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RHOMGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int*arrx = new int[4];
	int * arry = new int[4];
	arrx[0] = P1.x;
	arry[0] = P1.y + 70;
	arrx[1] = P1.x + 40;
	arry[1] = P1.y;
	arrx[2] = P1.x;
	arry[2] = P1.y - 70;
	arrx[3] = P1.x - 40;
	arry[3] = P1.y;


	pWind->DrawPolygon(arrx, arry, 4, style);
	delete[]arrx;
	delete[]arry;
}
void Output::DrawEllipse(Point P1, GfxInfo EllipseGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllipseGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllipseGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipseGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x + 30, P1.y + 50, P1.x - 30, P1.y - 50, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
