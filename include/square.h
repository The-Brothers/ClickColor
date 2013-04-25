#ifndef SQUARE_H
#define SQUARE_H

#include "SDL/SDL.h"

class Square{

	Uint32 red;
	Uint32 yellow;

	Uint32 color;

	SDL_Rect box;

	int i;
	int j;

public:
	Square(int cor, int _x, int _y, int _w, int _h, int _i, int _j);
	~Square();
	void draw();
	void update();

	int getI();
	int getJ();
	
	Uint32 getCor();
	void setCor(Uint32 nova_cor);

	SDL_Rect getBox();

	void mudarCor();
};

#endif