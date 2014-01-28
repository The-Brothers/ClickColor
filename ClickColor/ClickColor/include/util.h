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
		uint32_t setCustomColorKey(SDL_Surface *surfaceImage, uint32_t firstColorKey, uint32_t secondColorKey, uint32_t thirdColorKey);
	
	private:
};

#endif