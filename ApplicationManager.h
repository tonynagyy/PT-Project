#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions/Undo.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxFigCount = 200
	};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure *FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure *SelectedFig; //Pointer to the selected figure
	Input *pIn;/*pointer to the input */
	Output *pOut;/*pointer to the output */
	Action* Undoarray[5];/*array to save actions for undo*/
	Action* Redoarray[5];/*array to save actions for redo*/
	int UndoCount;
	int RedoCount;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SetInUndoList(Action* pAct);
	Action* GetLastUndo();
	void SetInRedoList(Action* pAct);
	Action* GetLastRedo();
	void DeleteAllRedos();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFig(CFigure* pFig);
	CFigure* GetSelectedFigFigure();
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void UnSelect();
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Functions related to play mode 
	CFigure *RandomFigure();
};

#endif