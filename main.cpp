#include "ApplicationManager.h"

int main() {
  	ActionType ActType;
 	ApplicationManager AppManager;

	do {		
		ActType = AppManager.GetUserAction();

		AppManager.ExecuteAction(ActType);

		AppManager.UpdateInterface();	

	} while(ActType != EXIT && ActType != GET_EXIT_PLAY);
	
	return (0);
}
