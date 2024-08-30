#include "GameBoard.h"



GameBoard::GameBoard(int startSize) {
	size = startSize;
	board.resize(size);
	for (int i = 0; i < size; i++) {
		board[i].resize(size);
	}
}
bool GameBoard::ValidateBoard() {
	return false;
}

string GameBoard::PrintBoard() {
	ostringstream ofs;
	for (int i = 0; i < size; i++) {
		for (int x = 0; x < size; x++) {
			ofs << "[" << board[i][x].value << "]";
		}
		ofs << endl;
	}
	return ofs.str();
}

bool GameBoard::InsertWord(string input, Cords worldCords) {
	PlacedWord temp = placedWords[placedWords.size() - 1];
	if (temp.dir == "vertical") {
		if (size - worldCords.y >= input.size()) {
			for (int i = 0; i < input.size(); i++) {
				board[worldCords.x][worldCords.y + i].value = input[i];
				board[worldCords.x][worldCords.y + i].placed = true;
			}
			placedWords.push_back(PlacedWord(input, worldCords, "horizontal"));
			return true;
		}
		else {
			return false;
		}
	}
	else if (temp.dir == "horizontal") {
		if (size - worldCords.x >= input.size()) {
			for (int i = 0; i < input.size(); i++) {
				board[worldCords.x + i][worldCords.y].value = input[i];
				board[worldCords.x + i][worldCords.y].placed = true;
			}
			placedWords.push_back(PlacedWord(input, worldCords, "vertical"));
		}
		else {
			return false;
		}
	}
}

bool GameBoard::Shift(string dir) {
	if (dir == "up") {
		vector<Box> row = board[0];
		for (int i = 0; i < row.size(); i++) {
			if (row[i].placed == true) {
				return false;
			}
		}
		for (int i = 0; i < placedWords.size(); i++) {
			placedWords[i].orgin.x -= 1;
		}
		for (int i = 0; i < size - 1; i++) {
			board[i] = board[i + 1];
		}
		board[size - 1] = row;
		return true;
	}
	else if (dir == "down") {
		vector<Box> row = board[size - 1];
		for (int i = 0; i < row.size(); i++) {
			if (row[i].placed == true) {
				return false;
			}
		}
		for (int i = 0; i < placedWords.size(); i++) {
			placedWords[i].orgin.x += 1;
		}
		for (int i = size - 1; i > 0; i--) {
			board[i] = board[i - 1];
		}
		board[0] = row;
		return true;
	}
	else if (dir == "right") {
		vector<Box> col;
		for (int i = 0; i < size; i++) {
			col.push_back(board[i][size - 1]);
			if (col[i].placed == true) {
				return false;
			}
		}
		for (int i = 0; i < placedWords.size(); i++) {
			placedWords[i].orgin.y += 1;
		}
		for (int i = 0; i < size; i++) {
			for (int x = size - 1; x > 0; x--) {
				board[i][x] = board[i][x - 1];
			}
		}
		for (int i = 0; i < size; i++) {
			board[i][0] = col[i];
		}
		return true;
	}
	else if (dir == "left") {
		vector<Box> col;
		for (int i = 0; i < size; i++) {
			col.push_back(board[i][0]);
			if (col[i].placed == true) {
				return false;
			}
		}
		for (int i = 0; i < placedWords.size(); i++) {
			placedWords[i].orgin.y -= 1;
		}
		for (int i = 0; i < size; i++) {
			for (int x = 0; x < size - 1; x++) {
				board[i][x] = board[i][x + 1];
			}
		}
		for (int i = 0; i < size; i++) {
			board[i][size - 1] = col[i];
		}
		return true;
	}
	else {
		cout << "error on shift direction";
		return false;
	}
}



Cords GameBoard::GetWorldCords(Cords crossPoint) {
	PlacedWord temp = placedWords[placedWords.size() - 1];
	if (temp.dir == "horizontal") {
		return Cords(temp.orgin.x - crossPoint.y, temp.orgin.y + crossPoint.x);
	}
	else {
		return Cords(temp.orgin.x + crossPoint.x, temp.orgin.y - crossPoint.y);
	}
}

bool GameBoard::RecursiveValInput(string input, Cords crossPoint) {
	PlacedWord temp = placedWords[placedWords.size() - 1];
	for (int i = 0; i < placedWords.size(); i++) {
		if (input == placedWords[i]) {
			return false;
		}
	}
	Cords worldOrgin = GetWorldCords(crossPoint);
	if (temp.dir == "horizontal") {
		if (worldOrgin.x >= 0 && worldOrgin.x + input.size() < size) {
			for (int i = 0; i < input.size(); i++) {
				if (board[worldOrgin.x + i][worldOrgin.y].placed == true) {
					return false;
				}
			}
			//YOU STOPPED HERE YOU DUMBASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
		}
	}
	else {

	}
}