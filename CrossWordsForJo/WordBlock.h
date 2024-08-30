#pragma once
#include <iostream>
#include <vector>
#include "Cords.h"
using namespace std;

class WordBlock
{
public:
	string baseWord;
	vector<string> crosses;
	WordBlock(string word, vector<string> rest);
	vector<Cords> FindCross(string input);
	

private:
	vector<string> WorkingWords(vector<string> rest);
};
