#ifndef BOARDBUILDER_H
#define BOARDBUILDER_H

#include <vector>
#include "board.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
class BoardBuilder{

	int numberOfLevels;
	vector<Board *> boards;

public:
	BoardBuilder();
	~BoardBuilder();

	Board* getBoard(int _level);
	void setScore(int _score);

};

#endif