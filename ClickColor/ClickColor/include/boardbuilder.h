#ifndef BOARDBUILDER_H
#define BOARDBUILDER_H

#include <vector>
#include "board.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

class BoardBuilder{

	vector<Board *> boards;

public:
	BoardBuilder(SDL_Surface *screen);
	~BoardBuilder();
	
	int numberOfLevels;

	Board* getBoard(int _level);
	void setScore(int _score);

};

#endif