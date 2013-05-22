#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "timer.h"
#include "util.h"
#include "board.h"
#include "gui.h"
#include "boardbuilder.h"

#define SCREEN_W 470
#define SCREEN_H 360
#define SCREEN_BPP 32

#define FPS 30

enum GameEstate{
	PLAYING,
	END_GAME
};

class Game{

	//Configs
	SDL_Surface* screen; //the game screen
	SDL_Event events; //the ingame events

	bool running; //sets the game running

	Uint32 start; //FPS control

	//The game board
	SDL_Surface* interface;
	Board* board;

	//The text that is written on the screen
	Gui* clicks;
	Gui* currentLevel;
	Gui* minimumClicks;
	Gui* victoryMessage;

	//Variable to count the number of clicks you made
	int clickCount;
	int levelCounter;
	int maxLevel;
	//The responsible to store all the levels
	BoardBuilder* boardbuilder;

public:
	Game(); //Constructor
	~Game(); //Destructor
	void run(); //THE GAME
	void handleEvents();

	void nextLevel();
};

#endif