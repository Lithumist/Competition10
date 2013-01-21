#ifndef CGAME_H
#define CGAME_H

/*
	This class manages the game from the highest level.
*/



// include
#include <ctime>
#include "cGlobalData.h"
#include "cPlayer.h"
#include "cMap.h"



// class
class cGame
{
public:
	// main classes
	cGlobalData GlobalData; // the data for the game
	cPlayer Player; // the player
	cMap mapCurrent; // the current map the player is on


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

	bool paused;
	sf::Image screenshot;



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