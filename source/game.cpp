#include "game.h"
#include "board.h"

//Contructor
Game::Game(){
	//Initialize all the SDL shit
	SDL_Init(SDL_INIT_EVERYTHING);
	//Set the main screen, the screen where the magic happens!
	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	//set the window title
	SDL_WM_SetCaption("ClickColor",NULL);

	//Set the game running
	this->running = true;

	//create a new board 3x3
	this->board = new Board(3);

	//Variable to count the number of clicks you made
	this->clickCount = 0;
}

//Destructor
Game::~Game(){
	//Free the screen surface
	SDL_FreeSurface(this->screen);
	//Quit the SDL elements
	SDL_Quit();
}

//
void Game::run(){

	while(this->running){
		this->start = SDL_GetTicks();
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				//If you click on the 'x'
				case SDL_QUIT:
					this->running = false;
				break;

				//if you click with the mouse
				case SDL_MOUSEBUTTONDOWN:
					//if you click the left button of the mouse
					if(events.button.button == SDL_BUTTON_LEFT){
						int x = events.button.x; //the position 'x' on the screen
						int y = events.button.y; //the position 'y' on the screen

						//Have you clicked on the board
						if(this->board->isClicked(x,y)){
							//click on the square on the board with this positions
							this->board->click(x,y);
							this->clickCount++;
						}
					}
				break;
			}
		}

		//Logic
		this->board->update();

		//Render -> draw on the screen surface
		this->board->draw();

		//Draw the screen surface on the screen
		SDL_Flip(screen);
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}