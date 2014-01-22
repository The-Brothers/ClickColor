#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "timer.h"
#include "util.h"
#include "board.h"
#include "button.h"
#include "gui.h"
#include "boardbuilder.h"
#include  <sstream>

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
	SDL_Window* window; // game window
	SDL_Surface* screen; //the game screen
	SDL_Event events; //the ingame events

	bool running; //sets the game running
	uint64_t start; //FPS control
	util* util;

	//The game board
	//Individual boards
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
	
	//This is used to store and manage all the levels
	BoardBuilder* boardbuilder;

	//The reset button
	Button *resetButton;

public:
	Game(); //Constructor
	~Game(); //Destructor
	
	
	void init();
	void setupGUI();
	void setupBoard();
	
	void run(); //THE GAME
	void handleEvents();

	void nextLevel();
};

#endif