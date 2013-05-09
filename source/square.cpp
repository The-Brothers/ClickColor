#include "square.h"
#include <iostream>

using namespace std;

//Constructor
Square::Square(int cor, int _x, int _y, int _w, int _h, int _i, int _j){
	//TODO: Put this somewherelse
	this->red = SDL_MapRGB(SDL_GetVideoSurface()->format,0xff,0x00,0x00);
	this->yellow = SDL_MapRGB(SDL_GetVideoSurface()->format,0xff,0xff,0x00);

	//Choose the color based on the parameter
	if(cor==1){
		this->color = red;
    }
	else{
		this->color = yellow;
    }

	//set the quare dimensions and position
	this->box.x = _x;
	this->box.y	= _y;
	this->box.h	= _h;
	this->box.w	= _w;
	//where the square is on the matrix
	this->i = _i;
	this->j = _j;
}

//destrucor
Square::~Square(){

}

//get the square color
Uint32 Square::getCor(){
	return this->color;
}
//set a new color for the square
//TODO: change the parameter for a global number
void Square::setCor(Uint32 _color){
	this->color = _color;
}

//get the box with the dimensions and position of the square
SDL_Rect Square::getBox(){
	return this->box;
}

//switch the color of the square
void Square::changeColor(){
	if(this->color == this->red){
		this->color = this->yellow;
	}
	else{
		this->color = this->red;
    }
}

//return the I and J, that are the postion of the square on the matrix
int Square::getI(){
	return this->i;
}

int Square::getJ(){
	return this->j;
}

