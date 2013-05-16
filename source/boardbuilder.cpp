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

BoardBuilder::BoardBuilder(){
	//Open the levels.map file
	ifstream levelmap("data/maps/levels.map");
	char buffin[4096];

	int _boardNumber;
	int _boardSize;
	int _score;
	string _levelLayout;
	//Reads it
 	int i=0;
	while(levelmap.getline(buffin,4096)){
	

		if(buffin[0] == '-'){
			levelmap.getline(buffin,4096);
			_boardNumber = atoi(buffin);

			levelmap.getline(buffin,4096);
			_boardSize = atoi(buffin);

			levelmap.getline(buffin,4096);
			_score = atoi(buffin);

			levelmap.getline(buffin,4096);
			_levelLayout = string(buffin);

			
			std::cout<<_boardNumber<<std::endl;
			std::cout<<_boardSize<<std::endl;
			std::cout<<_score<<std::endl;
			std::cout<<_levelLayout<<std::endl;
			
			boards.push_back(new Board(_boardNumber,  _boardSize,  _score, _levelLayout));
			i++;
		}
			
	}
	//FOR
		//Gets the information on it
		//Build a Board object
		//Store it in the boards vector
		//Increment the numberOfLevels
	//END FOR
}

BoardBuilder::~BoardBuilder(){

}

//Return the board at _level position on the boards vector
Board* BoardBuilder::getBoard(int _level){
	//level must be between 0 and the max number of levels	
	if(_level > 0 && _level < this->numberOfLevels)
		return this->boards.at(_level);
	
	else return NULL;
}

//Set the minimum number of clicks of a level and write it on the levels file
// void BoardBuilder::setScore(int _score){
	
// }