#ifndef UTIL_H
#define UTIL_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

using namespace std;

class util {
	public:
		util();
		
		//function to load images based on the name
		SDL_Surface * loadImage(const char* img);
	
	private:
};

#endif