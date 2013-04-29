#include "board.h"
#include "SDL/SDL.h"
#include <iostream>

using namespace std;

Board::Board(int boardSize){
	
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = BOARD_WIDTH;
	this->box.h = BOARD_HEIGHT;

	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			if((j+i)%2==0)
				squares.push_back(new Square(1,(j*BOARD_WIDTH/boardSize)+this->box.x,(i*BOARD_HEIGHT/boardSize)+this->box.y,100,100,i,j));
			else
				squares.push_back(new Square(0,(j*BOARD_WIDTH/boardSize)+this->box.x,(i*BOARD_HEIGHT/boardSize)+this->box.y,100,100,i,j));
		}
	}
}

Board::~Board(){

}

void Board::draw(){
	
	for(int i=0;i<(int)squares.size();i++){
		SDL_Rect temp = squares[i]->getBox();
		SDL_FillRect(SDL_GetVideoSurface(), &temp ,squares[i]->getCor());
	}
}

void Board::update(){

}

void Board::nextLevel(){

}

bool Board::isClicked(int x, int y){
	if(((x >= this->box.x) && (x<= (this->box.x + this->box.w))) && ((y >= this->box.y) && (y<= (this->box.y + this->box.h))))
		return true;
	return false;
}

void Board::click(int x, int y){
	for (int i=0;i<(int)this->squares.size();i++){
		SDL_Rect temp = squares[i]->getBox();
		if(	x >= temp.x && x <= temp.x + temp.w && y >= temp.y && y <= temp.y + temp.h){
			squares[i]->changeColor();

			changeNeighbors(i);
		}
	}
}

void Board::changeNeighbors(int i){
	int x, y;

	x = this->squares[i]->getI();
	y = this->squares[i]->getJ();
	
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