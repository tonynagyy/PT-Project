#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\helper.h"/**for overloading the operator the colors*/

/*
* Class: SaveAction inherited from Action
* @param fileName string to store the file name
* @param outFile ofstream to write into the file
* @param drawColor color to store the current draw color
* @param fillColor color to store the current fill color
* Description: This class is responsible for saving the current figures into a file
*/
class SaveAction : public Action
{
	string fileName;
	ofstream outFile;
	color drawColor;
	color fillColor;
public:
	SaveAction(ApplicationManager* pApp);
	void ReadActionParameters() override;
	void Execute() override;
	SaveAction *clone() const override;
	void undo() override;
};
