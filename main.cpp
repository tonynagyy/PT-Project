#include "ApplicationManager.h"
/*
* undo redo play reszie voice
* mario playmode  select 
* wagih drag clearall exit Addfig  move changeclolour
*/

int main()
{
  	ActionType ActType;
 	ApplicationManager AppManager;

	do
	{		
		ActType = AppManager.GetUserAction();

		AppManager.ExecuteAction(ActType);

		AppManager.UpdateInterface();	

	} while(ActType != EXIT && ActType != GET_EXIT_PLAY);
	
	return (0);
}
