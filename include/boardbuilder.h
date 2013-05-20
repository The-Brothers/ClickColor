#ifndef BOARDBUILDER_H
#define BOARDBUILDER_H

#include <vector>
#include "board.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
class BoardBuilder{

	vector<Board *> boards;

public:
	int numberOfLevels;
	BoardBuilder();
	~BoardBuilder();

	Board* getBoard(int _level);
	void setScore(int _score);

};

#endif