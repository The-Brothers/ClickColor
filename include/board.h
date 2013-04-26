#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include <vector>

#define Board_WIDTH 300
#define Board_HEIGHT 300

using namespace std;

class Board{
	SDL_Rect box;

	int size;
	vector<Square*> squares;

	int x;
	int y;

public: 
	Board(int boardSize);
	~Board();
	void draw();
	void update();
	void nextLevel();
	bool isClicked(int x, int y);
	void click(int x, int y);
	void changeNeighbors(int i);
};

#endif
