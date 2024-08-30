#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Cords.h"
#include "Box.h"
#include "PlacedWord.h"
using namespace std;


class GameBoard
{
public:
	vector<vector<Box>> board;
	vector<PlacedWord> placedWords;
	int size;
	GameBoard(int startSize);
	bool ValidateBoard();
	string PrintBoard();
	bool InsertWord(string input, Cords worldCords);
	bool Shift(string dir);
	Cords GetWorldCords(Cords crossPoint);
	bool RecursiveValInput(string input, Cords crossPoint);
};

