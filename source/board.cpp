#include "board.h"
#include "SDL/SDL.h"
#include <iostream>

using namespace std;

//Constructor
Board::Board(int boardSize){
	
	//Set the position of the board on the screen and it's dimensions
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = BOARD_WIDTH;
	this->box.h = BOARD_HEIGHT;

	for(int i=0;i<boardSize;i++){ //The line
		for(int j=0;j<boardSize;j++){ //The Column
			//configure the board to paint it based on the position on the board
			if((j+i)%2==0)
				squares.push_back(new Square(1,(j*BOARD_WIDTH/boardSize)+this->box.x,(i*BOARD_HEIGHT/boardSize)+this->box.y,100,100,i,j));
			else
				squares.push_back(new Square(0,(j*BOARD_WIDTH/boardSize)+this->box.x,(i*BOARD_HEIGHT/boardSize)+this->box.y,100,100,i,j));
		}
	}
}

//Destructor
Board::~Board(){

}

//Draw the board on the game screen
void Board::draw(){
	//go throught the square vector and draw each one.
	for(int i=0;i<(int)squares.size();i++){
		SDL_Rect temp = squares[i]->getBox(); //get the position and dimension of each square
		SDL_FillRect(SDL_GetVideoSurface(), &temp ,squares[i]->getCor()); //draw the square
	}
}

//do the Board logic
void Board::update(){

}

//redesign the board to becomee the next level board
void Board::nextLevel(){

}

//check if the board was clicked or not
bool Board::isClicked(int x, int y){
	//if the mouse click is inside the board coordinates
	if(((x >= this->box.x) && (x<= (this->box.x + this->box.w))) && ((y >= this->box.y) && (y<= (this->box.y + this->box.h))))
		return true; //true for "You clicked on the board!"
	return false; //false for "You clicked outside the board!"
}

//do the click action on a square on the board
void Board::click(int x, int y){
	//go through all the squares on the board and check if it was clicked or not
	for (int i=0;i<(int)this->squares.size();i++){
		SDL_Rect temp = squares[i]->getBox(); //get the current square dimensions
		//check if you clicked inside it
		if(	x >= temp.x && x <= temp.x + temp.w && y >= temp.y && y <= temp.y + temp.h){
			//chenge the color of the square that you clicked
			squares[i]->changeColor();
			//change the color of it neighbors
			changeNeighbors(i);
		}
	}
}

//Change the color of the neighbors of a certain square
void Board::changeNeighbors(int i){
	int x, y;

	//get the clicked square line 
	x = this->squares[i]->getI();
	//get the clicked square column
	y = this->squares[i]->getJ();


	//Go through all the squares on the board and check if they are the clicked square
	for (int i = 0; i <(int)squares.size(); ++i){
		if(squares[i]->getI() == x-1 && squares[i]->getJ() == y){
			squares[i]->changeColor();
			continue;
		}
		if(squares[i]->getI() == x+1 && squares[i]->getJ() == y){
			squares[i]->changeColor();
			continue;
		}
		if(squares[i]->getJ() == y-1 && squares[i]->getI() == x){
			squares[i]->changeColor();
			continue;
		}
		if(squares[i]->getJ() == y+1 && squares[i]->getI() == x){
			squares[i]->changeColor();
			continue;
		}
	}
}