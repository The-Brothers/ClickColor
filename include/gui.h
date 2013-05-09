#ifndef GUI_H
#define GUI_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include <string>

enum Color{
	RED,
	GREEN,
	BLUE,
	WHITE,
	BLACK
};

enum RenderType{
	SOLID,
	SHADED,
	BLENDED
};

using namespace std;

class Gui{

	TTF_Font* font;

	SDL_Surface* image;
	SDL_Color color;
	SDL_Color shadedColor;

	SDL_Rect box;

	string text;
	
	int fontsize;

	RenderType renderType;

public:
	Gui();
	Gui(char* _text, int _fontsize);
	~Gui();

	void draw();
	void update();

	void setText(char* _text);
	void setColor(int r, int g, int b);
	void setShadedColor(int r, int g, int b);
	void setFontSize(int size);
	void setRenderType(int _renderType);

};

#endif
