#include "gui.h"
#include <iostream>

using namespace std;

Gui::Gui(string _text, int _fontsize, int x, int y){
	box.x = x;
	box.y = y;

	SDL_Color _color = {0,0,0,0};
	color = _color;
	
	fontsize = _fontsize;
	font = TTF_OpenFont("data/font/Arista.ttf",fontsize);
	if(font == NULL)
		cout << TTF_GetError() << endl;
	text = _text;

	renderType = BLENDED;

	update();
}

Gui::~Gui(){
	TTF_CloseFont(font);
}

void Gui::draw(SDL_Surface *surface){
	SDL_BlitSurface(image,NULL,surface,&box);
}

void Gui::update(){
	switch(renderType){
		case SOLID:
			image = TTF_RenderText_Solid(font, text.c_str(), color);
		break;
		case SHADED:
			image = TTF_RenderText_Shaded(font,text.c_str(),color,shadedColor);
		break;
		case BLENDED:
			image = TTF_RenderText_Blended(font,text.c_str(),color);
		break;
	}
}

void Gui::setText(string _text){
	this->text = _text;
}

void Gui::setColor(Color _color){
	switch(_color){
		case RED:
			color = {0xff,0x00,0x00,0x00};
		break;
		case GREEN:
			color = {0x00,0xff,0x00,0x00};
		break;
		case BLUE:
			color = {0x00,0x00,0xff,0x00};
		break;
		case WHITE:
			color = {0xff,0xff,0xff,0x00};
		break;
		case BLACK:
			color = {0x00,0x00,0x00,0x00};
		break;
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

void Gui::setFont(string _fontpath){
	this->font = TTF_OpenFont(_fontpath.c_str(),this->fontsize);
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
