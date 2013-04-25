#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "square.h"
#include <vector>

#define TABULEIRO_WIDTH 300
#define TABULEIRO_HEIGHT 300

using namespace std;

class Tabuleiro{
	SDL_Rect box;

	int tamanho;
	vector<Square*> quadrados;

	int x;
	int y;

public: 
	Tabuleiro(int tamanhoTabuleiro);
	~Tabuleiro();
	void draw();
	void update();
	void mudarFase();
	bool isClicked(int x, int y);
	void click(int x, int y);
	void mudarAdjacente(int i);
};

#endif
