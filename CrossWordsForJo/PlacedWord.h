#pragma once
#include <iostream>
#include "Cords.h"

using namespace std;

class PlacedWord
{
public:
	string baseWord;
	Cords orgin;
	string dir;
	PlacedWord(string base, Cords o, string d);

};

