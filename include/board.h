#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include <vector>

// defines the board width and height
#define BOARD_WIDTH 300
#define BOARD_HEIGHT 300

using namespace std;

//class Board, the place where the action happens!
class Board{
	//The structure where the positions and dimensions are stored.
	SDL_Rect box;

	// The number of squares size x size the board will have
	int size;
	// The squares that form the game board
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
