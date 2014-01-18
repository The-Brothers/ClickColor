#include "game.h"

int main(){
	
	Game * game;
	game = new Game(); // triggers constructor
	
	//run the game
	game->run();
	
	delete game;

	return 0;
}