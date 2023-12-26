#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeletefigAction.h"
#include "Actions\PickFigAction.h"
#include "Actions\PickClrAction.h"
#include "Actions\PickClrFig.h"
#include "Actions\Undo.h"
#include "Actions\SelectFillColour.h"
#include "Actions\SelectDrawColour.h"
#include "Actions\SaveAction.h"
#include "Actions\clearall.h"
#include "Actions\MoveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\DraggingMove.h"
#include "Actions\ResizeAction.h"
#include "StopRecAction.h"	
#include "Actions\ExitActionh.h"
#include "SwitchModeAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxFigCount = 200
	};	//Max no of figures

private:
	bool Playvoice;     //boolean to play voice
	int FigCount;		//Actual number of figures
	int Actualfigcounter;	//Actual number of figures
	int actionsCount;	//Actual number of actions needed for start rec and play rec
	int UndoCount;
	int RedoCount;
	bool undoable;
	CFigure *FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure *SelectedFig; //Pointer to the selected figure
	Input *pIn;/*pointer to the input */
	Output *pOut;/*pointer to the output */
	Action* Undoarray[5];/*array to save actions for undo*/
	Action* Redoarray[5];/*array to save actions for redo*/
	Action* Startrecaction;
	Action* action;
	bool InRecording;//boolean to check if the user is in recording mode or not
	bool PlayRecStatus;//boolean to check if the user is in playing mode or not
public:	

	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	ActionType GetUserAction() const;
	Action* getActionPtr() const;
	void setActionPtr(Action* action);
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SetInUndoList(Action* pAct);
	Action* GetLastUndo();
	void SetInRedoList(Action* pAct);
	Action* GetLastRedo();
	void DeleteAllRedos();
	void Setundoable(bool b);
	void DeleteFigList();
	void Deleteundoarray();
	void Clearall();
	void SetInrecording(bool b);
	bool GetRecordStatus();
	Action*& GetStartrecaction();
	void SetPlayrec(bool b);
	bool GetPlayrecStatus();

	void SetPlayvoicestatus(bool b);     // setting the status to enable or disable
	bool Getplayvoicestatus();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFig(CFigure* pFig);
	void Changefillcolor(CFigure* pFig ,color clr);
	void Changedrawcolor(CFigure* pFig, color clr);
	void Movefigure(CFigure* pFig, double& x, double& y);
	CFigure* GetSelectedFigure();
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void UnSelect();
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	/*Save*/
	void saveAll(ofstream& outfile);
	int getActFigCount();
	/*Rec*/
	int getActionsCounter() const;// get the number of actions needed for start rec and play rec
	void setActionsCount(int count);// set it to -1 in case of clearAll

	// -- Functions related to play mode 
	CFigure *RandomFigure(); // choose a random figure
	bool CheckPlay(int I);  // check if there is a figure with the same identifier or not
	bool CheckPlay(color clr); // check if there is a figure with the same colour or not
	bool CheckPlay(); // check if there is a non-filled figure or not
	bool CheckPlay(int I, color clr); // check if there is a figure with the same identifier and colour or not
	void DrawingBack(); // return the figures after playing
};
#endif