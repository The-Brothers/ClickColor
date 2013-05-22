#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include <vector>
#include <string>

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

	//Board identificator
	int boardNumber;
	//Least number of clicks to solve the board
	int score;
	int boardSize;

	void buildBoard(string _levelLayout);

public: 
	Board(int boardSize); //Constructor
	Board(int boardNumber, int boardSize, int score, string levelLayout); //Constructor
	~Board();	//Destructor
	void draw();	//Draw the Board on the screen
	void update();	//Do the Board logic
	void nextLevel();	//Change the Board layout according to the next level
	bool isClicked(int x, int y);	//Check if the board was clicked
	void click(int x, int y);	//Performs a click on a square inside the Board
	void changeNeighbors(int i);	//change the color of the cell number i neighbors

	bool isVictory(); //go through the board to check if it is color uniform

	int getScore();
};

#endif
