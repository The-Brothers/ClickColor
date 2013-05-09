#include "gui.h"
#include <iostream>

using namespace std;

Gui::Gui(){
//TODO: Valores entrados pelo usuário
//TODO: Criar contrutor genérico e construtor do usuário
	this->box.x = 10;
	this->box.y = SDL_GetVideoSurface()->h/4 * 3;

	this->fontsize = 40;
	SDL_Color _color = {255,255,255,0};
	this->color = _color;
	this->text ="teste";
	this->font = TTF_OpenFont("data/font/Arista.ttf",this->fontsize);

	this->renderType = BLENDED;

	update();
}

Gui::Gui(string _text, int _fontsize){

	this->box.x = 10;
	this->box.y = SDL_GetVideoSurface()->h/4 * 3;

	SDL_Color _color = {255,255,255,0};
	this->color = _color;
	
	this->fontsize = _fontsize;
	this->font = TTF_OpenFont("data/font/Arista.ttf",this->fontsize);
	if(this->font==NULL)
		cout << TTF_GetError() << endl;
	this->text = _text;

	this->renderType = BLENDED;

	update();
}

Gui::Gui(string _text, int _fontsize, int x, int y){

	this->box.x = x;
	this->box.y = y;

	SDL_Color _color = {255,255,255,0};
	this->color = _color;
	
	this->fontsize = _fontsize;
	this->font = TTF_OpenFont("data/font/Arista.ttf",this->fontsize);
	if(this->font==NULL)
		cout << TTF_GetError() << endl;
	this->text = _text;

	this->renderType = BLENDED;

	update();
}

Gui::~Gui(){
	TTF_CloseFont(this->font);
}

void Gui::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Gui::update(){
	switch(this->renderType){
		case SOLID:
			this->image = TTF_RenderText_Solid(this->font,this->text.c_str(),this->color);
		break;
		case SHADED:
			this->image = TTF_RenderText_Shaded(this->font,this->text.c_str(),this->color,this->shadedColor);
		break;
		case BLENDED:
			this->image = TTF_RenderText_Blended(this->font,this->text.c_str(),this->color);
		break;
	}
}

void Gui::setText(string _text){
	this->text = _text;
}

void Gui::setColor(Color _color){
	switch(_color){
		case RED:
			this->color = {0xff,0x00,0x00,0x00};
		case GREEN:
			this->color = {0x00,0xff,0x00,0x00};
		case BLUE:
			this->color = {0x00,0x00,0xff,0x00};
		case WHITE:
			this->color = {0xff,0xff,0xff,0x00};
		case BLACK:
			this->color = {0x00,0x00,0x00,0x00};
	}
}

void Gui::setShadedColor(Color _color){
	switch(_color){
		case RED:
			this->shadedColor = {0xff,0x00,0x00,0x00};
		case GREEN:
			this->shadedColor = {0x00,0xff,0x00,0x00};
		case BLUE:
			this->shadedColor = {0x00,0x00,0xff,0x00};
		case WHITE:
			this->shadedColor = {0xff,0xff,0xff,0x00};
		case BLACK:
			this->shadedColor = {0x00,0x00,0x00,0x00};
	}
}

void Gui::setFontSize(int size){
	this->fontsize = size;
	this->font = TTF_OpenFont("data/Arista.ttf",this->fontsize);
}

void Gui::setRenderType(int _renderType){
	switch(_renderType){
		case SOLID:
			this->renderType = SOLID;
		break;
		case SHADED:
			this->renderType = SHADED;
		break;
		case BLENDED:
			this->renderType = BLENDED;
		break;
		default:
			cout << "Error: unknow render type." << endl;

	}
}
