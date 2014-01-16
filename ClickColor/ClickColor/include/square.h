#ifndef SQUARE_H
#define SQUARE_H

#include "SDL.h"
#include "SDL_surface.h"

class Square{

	//Colors
	//TODO: those colors must be somewhere else, like a library of colors
	Uint64 color1;
	Uint64 color2;

	// The square color
	Uint64 color;

	//The structure where the positions and dimensions are stored.
	SDL_Rect box;

	//where in the board the square is placed
	int i;
	int j;

public:

	Square(int cor, int _x, int _y, int _w, int _h, int _i, int _j, SDL_Surface *screen); //Constructor
	~Square(); //Destructor
	
	void draw(); // Draws the square on the game screen
	void update(); // Do the square logic
	
	//change the square color
	void changeColor();

	//Getters and setters
	int getI();
	int getJ();
	Uint64 getCor();
	void setCor(Uint64 nova_cor);
	SDL_Rect getBox();

};

#endif