#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "CMUgraphicsLib\colors.h"
using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;
using std::string;

std::ofstream& operator<<(std::ofstream& outFile, color& c);