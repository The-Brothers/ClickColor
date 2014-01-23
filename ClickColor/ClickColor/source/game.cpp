#include "SDL.h"
#include "SDL_error.h"
#include "SDL_video.h"
#include "SDL_surface.h"
#include "SDL_events.h"

#include "SDL_ttf.h"
#include "SDL_image.h"

#include "game.h"
#include "board.h"
#include "util.h"

//Contructor triggered will setup the game
Game::Game(){
	init();

	//Set the main window
	window = SDL_CreateWindow(
		"ClickColor",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_W,
		SCREEN_H,
		SDL_WINDOW_SHOWN
	);
	
	//THIS IS THE CODE THAT FIXED ALL THE BUGS! Game works now!
	screen = SDL_GetWindowSurface(window);
	
	//Set the game running
	running = true;

	//Variable to count the number of clicks you made
	clickCount = 0;
	
	//Variable to count the level so far
	levelCounter = 0;

	//Load the game user interface(SDL_Surface pointer)
	interface = util->loadImage("./data/image/ui.png");

	setupBoard();
	setupGUI();

	//Initialize the reset button
	resetButton = new Button("data/image/config.png",340,285);
}

//Destructor
Game::~Game(){
	//Free the interface(game board) surface
	SDL_FreeSurface(interface);
	//Free the screen surface
	SDL_FreeSurface(screen);
	//Free the game window
	SDL_DestroyWindow(window);
	
	delete boardbuilder;
	
	delete clicks;
	delete currentLevel;
	delete minimumClicks;
	delete victoryMessage;
	
	delete resetButton;

	//Close the TTF elements
	TTF_Quit();
	// Close the IMG elements
	IMG_Quit();
	//Quit the SDL elements
	SDL_Quit();
}

void Game::init() {
	//Initialize all the SDL shit
	if (!SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initialising SDL! SDL error message: " << SDL_GetError() << endl;
	}
	
	//Initialise word TTF
	TTF_Init();
	
	//Initialise IMG extension
	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);
	if (init != flags) {
		cout << "Error!" << endl;
	}
}

void Game::setupBoard() {
	//Build all the game boards that will be used by the game
	boardbuilder = new BoardBuilder(screen);
	//Load the first board
	board = boardbuilder->getBoard(levelCounter);
	//Sets the last level number
	maxLevel = boardbuilder->numberOfLevels-1;
}

void Game::setupGUI() {
	//Initialize the text field where the clicks you make are written
	clicks = new Gui("0",32,380,170);
	clicks->setColor(BLACK);
	
	//Initialize the current level
	currentLevel = new Gui("1",32,380,50);
	currentLevel->setColor(BLACK);
	
	//Initialize the minimum number of clicks needed to pass the level
	char temp[5];
	sprintf(temp,"%d", board->getScore());
	minimumClicks = new Gui(temp,32,380,110);
	minimumClicks->setColor(BLACK);
	
	//Initialize victory message
	victoryMessage = new Gui("You won!",32,340,290);
	victoryMessage->setColor(RED);
}

//main loop
void Game::run(){

	while(running){
		start = SDL_GetTicks();
		handleEvents();
		//Logic
		board->update();
		//continue to render the font
		clicks->update();

		//Render -> draw on the screen surface
		SDL_BlitSurface(interface,NULL,screen,NULL);
		//draw the board
		board->draw(screen);
		//render the clicks
		clicks->draw(screen);
		//draw current level
		currentLevel->draw(screen);
		//draw minimum clicks label
		minimumClicks->draw(screen);
		//draw the reset button
		resetButton->draw(screen);

		//Check if all the squares have the same color
		if(board->isVictory()){
			nextLevel();	
		}

		//Draw the screen surface on the screen
		SDL_UpdateWindowSurface(window);
		//FPS control
		if(1000/FPS > SDL_GetTicks() - start)
			//implicit conversion loses integer precision
			
			//SDL_Delay(1000/FPS - (uint32-t)(SDL_GetTicks() - start)); causes game to appear and disappear
			SDL_Delay(1000/FPS - (SDL_GetTicks() - start)); //this works fine
	}
}

void Game::handleEvents(){
	//Events
	while(SDL_PollEvent(&events)){
		switch(events.type){
			//If you click on the 'x'
			case SDL_QUIT:
				running = false;
			break;
				
			//On key press ESC Exit game
			case SDL_KEYDOWN:
	            switch (events.key.keysym.sym) {
	            	case SDLK_ESCAPE:
	                	running = false;
	                break;
	            	default:
	                break;
	          	}

			//If you click with the mouse
			case SDL_MOUSEBUTTONDOWN:
				//If you click the left button of the mouse
				if(events.button.button == SDL_BUTTON_LEFT){
					int x = events.button.x; //the position 'x' on the screen
					int y = events.button.y; //the position 'y' on the screen

					//Have you clicked on the board
					if(board->isClicked(x,y)){
						//Performs a click on the square on the board with this positions
						board->click(x,y);

						//Count the number of clicks you made
						clickCount++;
						
						//Update the click count on the screen
						stringstream temps;
						temps << clickCount;
						clicks->setText(string(temps.str()));
					}

					resetButton->isClicked(x,y);

				}
				
			break;
		}
	}
}

void Game::nextLevel(){	
	victoryMessage->update();
	victoryMessage->draw(screen);
	SDL_UpdateWindowSurface(window);
	//TODO: Remove this delay for a window message.
	//SDL_Delay(1000) removed, just commented out actually

	if(levelCounter < this->maxLevel){
		//Resets the click count
		clickCount = 0;

		//Resets the clicks display
		char temp[5]; 
		sprintf(temp,"%d", clickCount);
		clicks->setText(string(temp));

		//Resets the board
		board = boardbuilder->getBoard(levelCounter);
		
		//Increments the level counter
		levelCounter++;

		//Update the level counter on the screen
		sprintf(temp,"%d",this->levelCounter);
		currentLevel->setText(string(temp));
		currentLevel->update();

		//Update the minimum clicks text
		sprintf(temp,"%d",this->board->getScore());
		minimumClicks->setText(string(temp));
		minimumClicks->update();

	} else {
		running=false; //When you reach the last level the game ends.
	}
}