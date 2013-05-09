#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "timer.h"
#include "util.h"
#include "board.h"
#include "gui.h"

#define SCREEN_W 400
#define SCREEN_H 500
#define SCREEN_BPP 32

#define FPS 30

enum GameEstate{
	PLAYING,
	END_GAME
};

class Game{

	//Configs
	SDL_Surface* screen; //the game screen
	SDL_Surface* score;
	SDL_Event events; //the ingame events

	bool running; //sets the game running

	Uint32 start; //FPS control

	//The game board
	Board* board;
	Gui* clicks;

	//Variable to count the number of clicks you made
	int clickCount;
public:
	Game(); //Constructor
	~Game(); //Destructor
	void run(); //THE GAME
};

#endif