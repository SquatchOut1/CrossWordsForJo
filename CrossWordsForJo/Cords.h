#pragma once
class Cords
{
public:
	int x;
	int y;
	Cords() {
		x = -1;
		y = -1;
	}
	Cords(int f, int l) {
		x = f;
		y = l;
	}
	//Cords &operator=(Cords& toBeCopied);
};

