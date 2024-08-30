#include "WordBlock.h"
#include "GameBoard.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	const int endTime = 180;
	const int boardSize = 15;
	const string inputFile = "crossword.txt";
	
	string input;
	vector<string> inputWords;
	vector<WordBlock> wordBlocks;

	GameBoard gb(boardSize);
	
	ifstream ifs(inputFile);

	if (!ifs.is_open()) {
		cout << "Mb B forgot to put in the file";
	}

	while (getline(ifs, input)) {
		for (int i = 0; i < input.size(); i++) {
			input[i] = toupper(input[i]);
		}
		inputWords.push_back(input);
	}

	ifs.close();

	sort(inputWords.begin(), inputWords.end());

	for (int i = 0; i < inputWords.size(); i++) {
		wordBlocks.push_back(WordBlock(inputWords[i], inputWords));
	}

	cout << gb.PrintBoard();

	cout << endl << endl << gb.PrintBoard();

	return 0;
}