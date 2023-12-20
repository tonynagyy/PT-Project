#include "SaveAction.h"
#include "..\helper.h"

///*
//* operator<< - overloading the << operator to save the colors
//* @param outFile - ofstream object
//* @param c - color object
//* Description: overloading the << operator to save the colors for red, green, blue, black, orange, yellow and no fill
//*/
//std::ofstream& operator<<(std::ofstream& outFile,  color& c) {
//   color newColor = c;
//
//   if (newColor == BLACK) {
//	   outFile << "BLACK" << std::endl;
//   }
//   else if (newColor == RED) {
//	   outFile << "RED" << std::endl;
//   }
//   else if (newColor == GREEN) {
//	   outFile << "GREEN" << std::endl;
//   }
//   else if (newColor == BLUE) {
//	   outFile << "BLUE" << std::endl;
//   }
//   else if (newColor == ORANGE) {
//	   outFile << "ORANGE" << std::endl;
//   }
//   else if (newColor == YELLOW) {
//	   outFile << "YELLOW" << std::endl;
//   } else {
//	   outFile << "NO_FILL" << std::endl;
//   }
//   return outFile;
//}

/*
* SaveAction - constructor function
* @param pApp - pointer to ApplicationManager
* Description: constructor function that sets the pManager of the class
*/

SaveAction::SaveAction(ApplicationManager* pApp)
	:Action(pApp) {
}

/*
* ReadActionParameters - Reads the parameters of SaveAction
* Description: Reads the parameters of SaveAction from the user "file name"
*/
void SaveAction::ReadActionParameters() {

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
	int figCount = pManager->getFigCount();
	ReadActionParameters();
	outFile.open(fileName);

	drawColor =  outPtr->getCrntDrawColor();
	fillColor = outPtr->getCrntFillColor();
	// overload the << operator to save the colors

	if (outFile.is_open()) {
		outFile << drawColor << "\t";
		outFile << fillColor << endl;
		outFile << figCount << endl;
		pManager->saveAll(outFile);
		outFile.close();
	}
	else {
		outPtr->PrintMessage("file is not open");
		outPtr->ClearStatusBar();
	}

}
/*
* getFileName - getter function
* @return string - the file name
* Description: getter function that returns the file name
*/

const string& SaveAction::getFileName() const {
	return fileName;
}

/*
* setFileName - setter function
* @param fileName - the file name
*/
void SaveAction::setFileNmae(const string& fileName) {
		this->fileName = fileName;
}

SaveAction* SaveAction::clone() const {
	return NULL;
}

void SaveAction::undo() {
}

//SaveAction* SaveAction::clone() const
//{
//	return new SaveAction(*this)
//}

