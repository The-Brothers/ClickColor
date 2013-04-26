#include "game.h"
#include "board.h"

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("ClickColor",NULL);

	this->running = true;

	this->board = new Board(3);
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
	SDL_Quit();
}

void Game::run(){

	while(this->running){
		this->start = SDL_GetTicks();
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				case SDL_QUIT:
					this->running = false;
				break;

				case SDL_MOUSEBUTTONDOWN:
					if(events.button.button == SDL_BUTTON_LEFT){
						int x = events.button.x;
						int y = events.button.y;

						if(this->board->isClicked(x,y)){
							this->board->click(x,y);
						}
					}
				break;
			}
		}
		//Logic
		this->board->update();

		//Render
		this->board->draw();
		// SDL_FillRect(screen,&screen->clip_rect,amarelo);

		SDL_Flip(screen);
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}