#include "tabuleiro.h"
#include "SDL/SDL.h"
#include <iostream>

using namespace std;

Tabuleiro::Tabuleiro(int tamanhoTabuleiro){
	
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = TABULEIRO_WIDTH;
	this->box.h = TABULEIRO_HEIGHT;

	for(int i=0;i<tamanhoTabuleiro;i++){
		for(int j=0;j<tamanhoTabuleiro;j++){
			if((j+i)%2==0)
				quadrados.push_back(new Square(1,(j*TABULEIRO_WIDTH/tamanhoTabuleiro)+this->box.x,(i*TABULEIRO_HEIGHT/tamanhoTabuleiro)+this->box.y,100,100,i,j));
			else
				quadrados.push_back(new Square(0,(j*TABULEIRO_WIDTH/tamanhoTabuleiro)+this->box.x,(i*TABULEIRO_HEIGHT/tamanhoTabuleiro)+this->box.y,100,100,i,j));
		}
	}
}

Tabuleiro::~Tabuleiro(){

}

void Tabuleiro::draw(){
	
	for(int i=0;i<quadrados.size();i++){
		SDL_Rect temp = quadrados[i]->getBox();
		SDL_FillRect(SDL_GetVideoSurface(), &temp ,quadrados[i]->getCor());
	}
}

void Tabuleiro::update(){

}

void Tabuleiro::mudarFase(){

}

bool Tabuleiro::isClicked(int x, int y){
	if(((x >= this->box.x) && (x<= (this->box.x + this->box.w))) && ((y >= this->box.y) && (y<= (this->box.y + this->box.h))))
		return true;
	return false;
}

void Tabuleiro::click(int x, int y){
	for (int i=0;i<this->quadrados.size();i++){
		SDL_Rect temp = quadrados[i]->getBox();
		if(	x >= temp.x && x <= temp.x + temp.w && y >= temp.y && y <= temp.y + temp.h){
			quadrados[i]->mudarCor();

			mudarAdjacente(i);
		}
	}
}

void Tabuleiro::mudarAdjacente(int i){
	int x, y;

	x = this->quadrados[i]->getI();
	y = this->quadrados[i]->getJ();
	
	for (int i = 0; i < quadrados.size(); ++i){
		if(quadrados[i]->getI() == x-1 && quadrados[i]->getJ() == y){
			quadrados[i]->mudarCor();
			continue;
		}
		if(quadrados[i]->getI() == x+1 && quadrados[i]->getJ() == y){
			quadrados[i]->mudarCor();
			continue;
		}
		if(quadrados[i]->getJ() == y-1 && quadrados[i]->getI() == x){
			quadrados[i]->mudarCor();
			continue;
		}
		if(quadrados[i]->getJ() == y+1 && quadrados[i]->getI() == x){
			quadrados[i]->mudarCor();
			continue;
		}
	}
}