#pragma once

#include "Action.h"
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

class LoadAction : public Action {

	private:
		string fileName;
		ifstream inFile;
	public:
		color drawColor;
		color fillColor;

		LoadAction(ApplicationManager* pApp);
		void ReadActionParameters() override;
		void undo() override;
		void Execute() override;
		LoadAction* clone() const override;
};
