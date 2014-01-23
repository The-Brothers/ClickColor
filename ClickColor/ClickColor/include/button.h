#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"
#include "util.h"

using namespace std;

class Button{
	
	SDL_Rect box;

	SDL_Surface * image;
	
	util *util;

public:
	Button(const char* img, int _x, int _y);
	~Button();

	void draw(SDL_Surface *screen);
	void update();
	void resetAction();

	void isClicked(int x, int y);

};

#endif
