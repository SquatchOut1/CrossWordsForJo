#include "WordBlock.h"



WordBlock::WordBlock(string word, vector<string> rest) {
	baseWord = word;
	crosses = WorkingWords(rest);
}


vector<string> WordBlock::WorkingWords(vector<string> rest) {
	vector<string> crosses;
	bool addedWord = false;
	for (int i = 0; i < rest.size(); i++) {
		for (int x = 0; x < rest[i].size(); x++) {
			for (int y = 0; y < baseWord.size(); y++) {
				if (baseWord[y] == rest[i][x] && baseWord != rest[i]) {
					crosses.push_back(rest[i]);
					addedWord = true;
					break;
				}
			}
			if (addedWord) {
				addedWord = false;
				break;
			}
		}
	}
	return crosses;
}


vector<Cords> WordBlock::FindCross(string input) {
	vector<Cords> cords;
	for (int i = 0; i < baseWord.size(); i++) {
		for (int y = 0; y < input.size(); y++) {
			if (baseWord[i] == input[y]) {
				cords.push_back(Cords(i, y));
			}
		}
	}
	return cords;
}
