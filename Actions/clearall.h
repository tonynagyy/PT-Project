#ifndef CLEAR_ALL_H
#define	CLEAR_ALL_H

#include "Action.h"
#include "..\ApplicationManager.h"
class clearAll : public Action {
private:
	string warningMsg;
public:
	clearAll(ApplicationManager * pMan);
	void ReadActionParameters() override;
	void Execute() override;
	void undo() override;
	Action* clone() const override;
	
};
#endif

