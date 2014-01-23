#include "boardbuilder.h"

/** FORMATO DO ARQUIVO
- //significa que abaixo estão as informações de um level
1 //numero do level
4 //minimo de clicks para solucionar o level
3 //tamanho do level
0,1,0,1,0,1,0,1,0 //formato do level
- //abaixo um exemplo
2
100
3
1,1,1,0,0,0,1,1,1

**/
using namespace std;
BoardBuilder::BoardBuilder(SDL_Surface *screen){
	//Open the levels.map file
	ifstream levelmap("data/maps/levels.map");
	
	char buffin[4096];

	int _boardNumber;
	int _boardSize;
	int _score;
	string _levelLayout;
	numberOfLevels = 0;
	
	//search and iterate through .map file for available levels
	while(levelmap.getline(buffin,2)){
		//if there's another level
		if(buffin[0] == '-'){
			//read level.map
			levelmap.getline(buffin,2);
			//set board number
			_boardNumber = atoi(buffin);
    
			//read level.map
			levelmap.getline(buffin,2);
			//set board number
			_boardSize = atoi(buffin);
			
			//read level.map
    		levelmap.getline(buffin,2);
			//set score
			_score = atoi(buffin);

			//read level.map
			levelmap.getline(buffin, _boardSize * _boardSize + 1);
			//sets out the level layout
			_levelLayout = string(buffin);
			
			//push board vector for new board
			//push new board into vector to set it up
			boards.push_back(new Board(_boardNumber,  _boardSize,  _score, _levelLayout, screen));
			//increment the level number
			numberOfLevels++;
		}	
	}
	
	// if there are no more available levels, increment number of levels
	numberOfLevels++;
}

BoardBuilder::~BoardBuilder(){
}

Board* BoardBuilder::getBoard(int _level){
	//level must be between 0 and the max number of levels	
	if(_level >= 0 && _level < numberOfLevels) {
		return boards.at(_level); //Return the board at _level position on the boards vector
	}
	
	return NULL;
}

//Set the minimum number of clicks of a level and write it on the levels file
// void BoardBuilder::setScore(int _score){

//}