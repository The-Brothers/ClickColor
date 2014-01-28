#include "square.h"
#include <iostream>

using namespace std;

//Constructor
Square::Square(int cor, int _x, int _y, int _w, int _h, int _i, int _j, SDL_Surface *screen){
	//TODO: Put this somewherelse
	//this works in mac os x
	color1 = SDL_MapRGB(screen->format,0xc9,0x53,0x87);
	color2 = SDL_MapRGB(screen->format,0xcd,0xdb,0x74);

	//Choose the color based on the parameter
	if(cor==1)
		this->color = color1;
	else
		this->color = color2;
	
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
Uint64 Square::getCor(){
	return color;
}
//set a new color for the square
//TODO: change the parameter for a global number
void Square::setCor(Uint64 _color){
	this->color = _color;	
}

//get the box with the dimensions and position of the square
SDL_Rect Square::getBox(){
	return this->box;
}

//switch the color of the square
void Square::changeColor(){
	if(this->color == this->color1){
		this->color = this->color2;
	}
	else
		this->color = this->color1;
}

//return the I and J, that are the postion of the square on the matrix
int Square::getI(){
	return this->i;
}

int Square::getJ(){
	return this->j;
}