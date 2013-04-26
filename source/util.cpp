#include "util.h"

using namespace std;

SDL_Surface * loadImage(const char* img){
	// TODO: check the image extension, like .png .bmp or .jpeg
	// Initialize the surface that will load the image
	SDL_Surface * loadedImage = NULL;
	
	// Initialize the surface where the opitimized image will be loaded
	SDL_Surface * optimizedImage =  NULL;
	
	// Loading the image
	loadedImage = IMG_Load(img);
	
	//If the image wasn't loaded sucessfully
	if(!loadedImage)
	{
		cout << "Error: " << SDL_GetError() << endl;
		return NULL;
	}
	
	// Time to optimize the loaded image
    optimizedImage = SDL_DisplayFormat(loadedImage);
    
    // Free the loadedImage surface from the memory
    SDL_FreeSurface(loadedImage);
    
    // Time to make the colorkeying
    //TODO: Make a parameter where you pass the color you want to use for colokeying
    // Load the color to do the colorkey
    Uint32 colorkey = SDL_MapRGB(optimizedImage->format,0xff,0x00,0xff);
    // Apply the colorkey
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);

    //Return the optimized image
    return optimizedImage;
}