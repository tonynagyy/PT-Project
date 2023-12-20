#include "helper.h"
/*
* operator<< - overloading the << operator to save the colors
* @param outFile - ofstream object
* @param c - color object
* Description: overloading the << operator to save the colors for red, green, blue, black, orange, yellow and no fill
*/
std::ofstream& operator<<(std::ofstream& outFile, color& c) {
	color newColor = c;

	if (newColor == BLACK) {
		outFile << "BLACK";
	}
	else if (newColor == RED) {
		outFile << "RED";
	}
	else if (newColor == GREEN) {
		outFile << "GREEN";
	}
	else if (newColor == BLUE) {
		outFile << "BLUE";
	}
	else if (newColor == ORANGE) {
		outFile << "ORANGE";
	}
	else if (newColor == YELLOW) {
		outFile << "YELLOW";
	}
	else {
		outFile << "NO_FILL";
	}
	return outFile;
}