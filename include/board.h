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
	Board(int boardSize); //Constructor
	~Board();	//Destructor
	void draw();	//Draw the Board on the screen
	void update();	//Do the Board logic
	void nextLevel();	//Change the Board layout according to the next level
	bool isClicked(int x, int y);	//Check if the board was clicked
	void click(int x, int y);	//performs a click on a square inside the Board
	void changeNeighbors(int i);	//change the color of the cell number i neighbors
};

#endif

