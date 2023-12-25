#pragma once
#include "Action.h"
#include "SaveAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\defs.h"
#include <string>
#include <fstream>
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;

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
	SaveAction * clone() const override;
	void undo() override;

};
