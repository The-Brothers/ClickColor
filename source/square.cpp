#include "square.h"
#include <iostream>

using namespace std;

Square::Square(int cor, int _x, int _y, int _w, int _h, int _i, int _j){
	
	this->red = SDL_MapRGB(SDL_GetVideoSurface()->format,0xff,0x00,0x00);
	this->yellow = SDL_MapRGB(SDL_GetVideoSurface()->format,0xff,0xff,0x00);

	if(cor==1)
		this->color = red;
	else
		this->color = yellow;
	
	this->box.x = _x;
	this->box.y	= _y;
	this->box.h	= _h;
	this->box.w	= _w;
	this->i = _i;
	this->j = _j;
}

Square::~Square(){

}

Uint32 Square::getCor(){
	return this->color;
}

void Square::setCor(Uint32 _color){
	this->color = _color;	
}

SDL_Rect Square::getBox(){
	return this->box;
}

void Square::changeColor(){
	if(this->color == this->red){
		this->color = this->yellow;
	}
	else
		this->color = this->red;
}

int Square::getI(){
	return this->i;
}

int Square::getJ(){
	return this->j;
}