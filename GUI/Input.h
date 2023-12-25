#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

//bool COLOURRS = false;

class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Input(window* pW);		//Consturctor
	void GetPointClicked(int& x, int& y) const; //Get coordinate where user clicks
	string GetSrting(Output* pO) const;	 // Returns a string entered by the user
	ActionType GetUserAction() const; // Read the user click and map to an action
	ActionColour GetColourAction(DrawMenuItem ITM) const; // read colours
	void StopStoringClicks() const;
	void StopStoringKeys() const;
	bool ClickingStatus(int& x, int& y); // Checking if the user still clicking in the left button or not 

	~Input();
};
#endif /*INPUT_H*/