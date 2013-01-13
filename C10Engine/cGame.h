#ifndef CGAME_H
#define CGAME_H

/*
	This class manages the game from the highest level.
*/



// include
#include "cGlobalData.h"



// class
class cGame
{
public:
	// main classes
	cGlobalData GlobalData; // the data for the game


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
	void newGame();
	bool loadGame();





private:
};


#endif