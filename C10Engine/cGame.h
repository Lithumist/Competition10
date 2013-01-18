#ifndef CGAME_H
#define CGAME_H

/*
	This class manages the game from the highest level.
*/



// include
#include "cGlobalData.h"
#include "cPlayer.h"



// class
class cGame
{
public:
	// main classes
	cGlobalData GlobalData; // the data for the game
	cPlayer Player; // the player


	// other varibles
	int currentState;
	/*
		0	intro
		1
		2
		3
		4
		5	main menu
	*/




	// constructor
	cGame();

	// methods
	bool startGame();
	void endGame();

	// loop
	bool loop();
	bool events();
	void step();
	void draw();





private:
};


#endif