// cGame.cpp
#include "cGame.h"


// constructor
cGame::cGame()
{
	currentState = 0;
}








// startGame
bool cGame::startGame()
{
	// create the global holder
	//GlobalData();

	// create the window
	GlobalData.windowMain.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT,32),WINDOW_CAPTION,sf::Style::Close);

	// set the target fps
	GlobalData.windowMain.setFramerateLimit(GAME_FPS);

	return true;
}

// endGame
void cGame::endGame()
{
	// close the window
	GlobalData.windowMain.close();
}









// loop
bool cGame::loop()
{
	while(true)
	{
		if(!events())
			break;
		
		step();

		draw();
	}

	return true;
}


// events
bool cGame::events()
{
	// events
	sf::Event ev;
	while(GlobalData.windowMain.pollEvent(ev))
	{

		// window closed
		if(ev.type == sf::Event::Closed)
			return false;

	}
	return true;
}


// step
void cGame::step()
{
}

// draw
void cGame::draw()
{
	// clear the window
	GlobalData.windowMain.clear();

	// display the painted window
	GlobalData.windowMain.display();
}