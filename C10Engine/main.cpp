/*
	
	Pedro Custodio 2013


	Unnamed game for the 10th Moosader Boards competition

*/


#include <iostream>

#include "cGame.h"

int main()
{
	std::cout << "Competition 10!\n";

	cGame gameMain;

	gameMain.startGame();

	gameMain.loop();

	gameMain.endGame();

	return 0;
}