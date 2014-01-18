#include "button.h"
#include "util.h"

using namespace std;

Button::Button(const char* img, int _x, int _y){
	this->image = util->loadImage(img);
	this->box.x = _x;
	this->box.y = _y;

	this->box.w = image->w;
	this->box.h = image->h;
}

Button::~Button(){
	SDL_FreeSurface(this->image);
}

void Button::draw(SDL_Surface *screen){
	SDL_BlitSurface(this->image,NULL,screen,&this->box);
}

void Button::resetAction(){
	cout<<"RESET action"<<endl;
}

//check if the board was clicked or not
void Button::isClicked(int x, int y){
	//if the mouse click is inside the board coordinates
	if(((x >= this->box.x) && (x<= (this->box.x + this->box.w))) && ((y >= this->box.y) && (y<= (this->box.y + this->box.h))))
		resetAction();
}
