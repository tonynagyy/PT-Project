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

//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxFigCount = 200
	};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int Actualfigcounter;	//Actual number of figures
	int actionsCount;
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
	bool InRecording;
	bool PlayRecStatus;
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
	Action* GetStartrecaction();
	void SetPlayrec(bool b);
	bool GetPlayrecStatus();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFig(CFigure* pFig);
	void Changefillcolor(CFigure* pFig ,color clr);
	void Changedrawcolor(CFigure* pFig, color clr);
	void Movefigure(CFigure* pFig, int x, int y);
	CFigure* GetSelectedFigure();
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void UnSelect();
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	/*Save*/
	void saveAll(ofstream &outfile) ;
	int getActFigCount() ;
	int getActionsCounter() const ;

	// -- Functions related to play mode 
	CFigure *RandomFigure(); // choose a random figure
	bool CheckPlay(int I);  // check if there is a figure with the same identifier or not
	bool CheckPlay(color clr); // check if there is a figure with the same colour or not
	bool CheckPlay(); // check if there is a non-filled figure or not
	bool CheckPlay(int I, color clr); // check if there is a figure with the same identifier and colour or not
	void DrawingBack(); // return the figures after playing
};
#endif