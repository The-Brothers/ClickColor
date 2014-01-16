#include "SDL_surface.h"
#include "util.h"

using namespace std;

util::util() {
}

SDL_Surface* util::loadImage(const char* img){
	// TODO: check the image extension, like .png .bmp or .jpeg
	// Initialize the surface and load the image
	SDL_Surface * loadedImage = IMG_Load(img);
	
	//If the image wasn't loaded sucessfully
	if(!loadedImage)
	{
		cout << "Error: " << SDL_GetError() << endl;
		return NULL;
	}
	
	// Time to make the colorkeying
    // TODO: Make a parameter where you pass the color you want to use for colokeying
    // Load the color to do the colorkey
    Uint32 colorkey = SDL_MapRGB(loadedImage->format,0xff,0x00,0xff);
    // Apply the colorkey
    SDL_SetColorKey(loadedImage, SDL_TRUE, colorkey);
	
	// Time to optimize the loaded image
    SDL_Surface *optimizedImage = SDL_ConvertSurface(loadedImage, loadedImage->format, 0);
    
    // Free the loadedImage surface from the memory
    SDL_FreeSurface(loadedImage);

    //Return the optimized image
    return optimizedImage;
}
