#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2,P3;




	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();





	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Square, Normal and Highlighted
	// 2.1.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->Drawsquare(P1, gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared

	// 2.1.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawsquare(P1, gfxInfo, true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.1.3 - Drawing a filled square
	pOut->PrintMessage("Drawing a square ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->Drawsquare(P1, gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.1.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawsquare(P1, gfxInfo, true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();





	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Triangle in all possible states
	// 2.3.1 - Drawing non-filled TRIANGLE
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->Drawtriangle(P1, P2 , P3 , gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.3.2 - Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawtriangle(P1, P2 , P3 , gfxInfo, true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.3.3 - Drawing a filled triangle
	pOut->PrintMessage("Drawing a triangle ==> filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->Drawtriangle(P1, P2 , P3 , gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.3.4 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Drawing a triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawtriangle( P1 , P2 , P3 , gfxInfo , true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	



	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states
	// 2.4.1 - Drawing non-filled HEXAGON
	pOut->PrintMessage("Drawing a HEXAGON ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);


	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->Drawhexagon(P1 , gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.4.2 - Drawing highlighted non-filled HEXAGON
	pOut->PrintMessage("Drawing a HEXAGON ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut-> Drawhexagon ( P1 , gfxInfo, true );
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared

	
	// 2.4.3 - Drawing a filled HEXAGON
	pOut->PrintMessage("Drawing a HEXAGON ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->Drawhexagon (P1 , gfxInfo, false);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.4.4 - Drawing a highlighted filled HEXAGON
	pOut->PrintMessage("Drawing a HEXAGON ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->Drawhexagon ( P1 , gfxInfo, true);
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states
	// 2.5.1 - Drawing non-filled CIRCLE
	pOut->PrintMessage("Drawing a CIRCLE ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);


	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut-> Drawcircle ( P1 , P2 , gfxInfo , false );
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.5.2 - Drawing highlighted non-filled CIRCLE
	pOut-> PrintMessage ("Drawing a CIRCLE ==> Highlighted non-filled, Click to Highlight") ;
	pIn-> GetPointClicked (x, y) ;	//Wait for any click
	pOut-> Drawcircle (P1 , P2 , gfxInfo, true) ;
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.5.3 - Drawing a filled CIRCLE
	pOut-> PrintMessage(" Drawing a CIRCLE ==> filled,  Click two points ");
	pIn-> GetPointClicked ( P1.x, P1.y ) ;
	pIn->GetPointClicked(P2.x, P2.y);


	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut-> Drawcircle ( P1 , P2 , gfxInfo, false ) ;
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	// 2.5.4 - Drawing a highlighted filled CIRCLE
	pOut-> PrintMessage ( "Drawing a CIRCLE ==> Highlighted filled, Click to Highlight");
	pIn-> GetPointClicked ( x , y );	//Wait for any click
	pOut-> Drawcircle ( P1 , P2 , gfxInfo, true ) ;
	pOut->CreateDrawToolBar(); // if you draw on toolbar it will be cleared


	pOut-> PrintMessage ( " Drawing a Circle Test ==> OK,  Click anywhere to continue " );
	pIn-> GetPointClicked(x,y);	//Wait for any click
	pOut-> ClearDrawArea();
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case SAVE:
			pOut->PrintMessage("Action: a click on save button , Click anywhere");
			break;

		case LOAD:
			pOut->PrintMessage("Action: a click on load button , Click anywhere");
			break;

		case UNDO:
			pOut->PrintMessage("Action: a click on undo button , Click anywhere");
			break;

		case REDO:
			pOut->PrintMessage("Action: a click on redo button , Click anywhere");
			break;

		case START_REC:
			pOut->PrintMessage("Action: Start recording , Click anywhere");
			break;

		case STOP_REC:
			pOut->PrintMessage("Action: Stop recording , Click anywhere");
			break;

		case PLAY_REC:
			pOut->PrintMessage("Action: Playing recording , Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: a click on select button , Click anywhere");
			break;

		case MOVE:
			pOut->PrintMessage("Action: a click on move button , Click anywhere");
			break;

		case CLEAR:
			pOut->PrintMessage("Action: a click on clear button , Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: a click on delete button , Click anywhere");
			break;

		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;
		
		case DRAW_CIRC:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			break;

		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;

		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			break;
 
		case DRAW_SQ:
			pOut->PrintMessage("Action: Draw a Sqaure , Click anywhere");
			break;

		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case HIGH_FRAME:
			pOut->PrintMessage("Action: Highlighted the frame , Click anywhere");
			break;

		case FILL:
			pOut->PrintMessage("Action: Filling the figure , Click anywhere");
			break;

		case COLOURS:
			pOut->PrintMessage("Action: Select a colour , Click anywhere");
			break;

		case F1:
			pOut->PrintMessage("Action: A7A , Click anywhere");
			break;

		case F2:
			pOut->PrintMessage("Action: Double A7A , Click anywhere");
			break;

		case F3:
			pOut->PrintMessage("Action: Triple A7A , Click anywhere");
			break;


		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");

				pOut->CreatePlayToolBar();
				break;

		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;


		///TODO: Add more cases for the other action types


		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


