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

/*
* operator>> - overloading the >> operator to load the colors
* @param inFile - ifstream object
* @param c - color object
* Description: overloading the >> operator to load the colors for red, green, blue, black, orange, yellow and no fill
* Return: color Reference
*/
color& operator>>(std::ifstream& inFile, color& c) {
	string colorName;
	inFile >> colorName;
	if (colorName == "BLACK") {
		c = BLACK;
	}
	else if (colorName == "RED") {
		c = RED;
	}
	else if (colorName == "GREEN") {
		c = GREEN;
	}
	else if (colorName == "BLUE") {
		c = BLUE;
	}
	else if (colorName == "ORANGE") {
		c = ORANGE;
	}
	else if (colorName == "YELLOW") {
		c = YELLOW;
	}
	else {
		c = SNOW;
	}
	return c;
}	





