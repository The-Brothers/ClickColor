#include "game.h"
#include "board.h"
#include "util.h"
#include "SDL/SDL_ttf.h"

//Contructor
Game::Game(){
	//Initialize all the SDL shit
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	//Set the main screen, the screen where the magic happens!
	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	//set the window title
	SDL_WM_SetCaption("ClickColor",NULL);

	//Set the game running
	this->running = true;


	//Variable to count the number of clicks you made
	this->clickCount = 0;
	this->levelCounter = 0;

	//create a gui to write the clicks you made
	this->clicks = new Gui(string("0"),32,380,170);
	this->clicks->setColor(BLACK);

	//load the game interface
	this->interface = loadImage("./data/image/ui.png");

	this->victoryMessage = new Gui(string("You won!"),32,340,290);
	victoryMessage->setColor(RED);
	
	this->boardbuilder= new BoardBuilder();
	//load the first board
	this->board = this->boardbuilder->getBoard(this->levelCounter);
	this->maxLevel =this->boardbuilder->numberOfLevels-1;
}

//Destructor
Game::~Game(){
	//Free the interface surface
	SDL_FreeSurface(this->interface);
	//Free the screen surface
	SDL_FreeSurface(this->screen);
	//Close the TTF elements
	TTF_Quit();
	//Quit the SDL elements
	SDL_Quit();
}

//
void Game::run(){

	while(this->running){
		this->start = SDL_GetTicks();
		handleEvents();
		//Logic
		this->board->update();
		this->clicks->update();

		//Render -> draw on the screen surface
		// SDL_FillRect(SDL_GetVideoSurface(),NULL,SDL_MapRGB(SDL_GetVideoSurface()->format,0x00,0x00,0x00));
		SDL_BlitSurface(this->interface,NULL,SDL_GetVideoSurface(),NULL);
		this->board->draw();
		this->clicks->draw();

		//Check if all the squares have the same color
		if(this->board->isVictory()){
			nextLevel();	
		}

		//Draw the screen surface on the screen
		SDL_Flip(screen);
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}

void Game::handleEvents(){
	//Events
	while(SDL_PollEvent(&this->events)){
		switch(this->events.type){
			//If you click on the 'x'
			case SDL_QUIT:
				this->running = false;
			break;
				
				//on key press ESC Exit game
				case SDL_KEYDOWN:
	            switch (events.key.keysym.sym) {
	            	case SDLK_ESCAPE:
	                	this->running = false;
	                break;
	            	default:
	                break;
	          	}

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

						//Count the number of clicks you made
						this->clickCount++;
						char temp[5];
						sprintf(temp,"%d",this->clickCount);
						this->clicks->setText(string(temp));
					}
				}
			break;
		}
	}
}

void Game::nextLevel(){	
	victoryMessage->update();
	victoryMessage->draw();
	SDL_Flip(screen);
	SDL_Delay(1000);

	if(this->levelCounter < this->maxLevel){
		//Resets the click count
		this->clickCount = 0;

		//Resets the clicks display
		char temp[5]; 
		sprintf(temp,"%d",this->clickCount);
		this->clicks->setText(string(temp));

		//Resets the board
		this->board = this->boardbuilder->getBoard(this->levelCounter);

		//Increments the level counter
		this->levelCounter++;
	}else this->running=false;
}