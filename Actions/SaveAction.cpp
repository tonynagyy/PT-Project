#include "SaveAction.h"

/*
* SaveAction - constructor function
* @param pApp - pointer to ApplicationManager
* Description: constructor function that sets the pManager of the class
*/
SaveAction::SaveAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

/*
* ReadActionParameters - Reads the parameters of SaveAction
* Description: Reads the parameters of SaveAction from the user "file name"
*/
void SaveAction::ReadActionParameters() 
{

	Output* outPtr = pManager->GetOutput();
	Input* inPtr = pManager->GetInput();

	outPtr->PrintMessage("plz entter the file name to save ");
	fileName = inPtr->GetSrting(outPtr);
	outPtr->ClearStatusBar();
}

/*
* Execute - Executes the save action overriden function
* Description: Executes the save action
* open file get colors and number of figures
* make a loop to save all figures using the save function in each figure
* */
void SaveAction::Execute()
{
	Output* outPtr = pManager->GetOutput();
	int figCount = pManager->getActFigCount();

	ReadActionParameters();/*get file Name into fileName*/
	outFile.open(fileName);

	drawColor =  outPtr->getCrntDrawColor();
	fillColor = outPtr->getCrntFillColor();

	if (outFile.is_open()) 
	{
		outFile << drawColor << "\t";
		outFile << fillColor << endl;
		outFile << figCount << endl;
		pManager->saveAll(outFile);
		outFile.close();
	}
	else 
	{
		outPtr->PrintMessage("file is not open");
		outPtr->ClearStatusBar();
	}
}

/*
* clone - clones the save action
* Description: Return NULL as it is not needed
* but must be implemented sice pure virtual
*/
SaveAction* SaveAction::clone() const 
{
	return (NULL);
}

void SaveAction::undo() 
{
}

