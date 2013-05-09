#ifndef UTIL_H
#define UTIL_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

using namespace std;

//function to load images based on the name
SDL_Surface * loadImage(const char* img);

#endif

