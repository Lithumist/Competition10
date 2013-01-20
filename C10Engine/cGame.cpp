// cGame.cpp
#include "cGame.h"


// constructor
cGame::cGame()
{
	cGlobalData GlobalData;
	currentState = 0;
	paused = false;
}








// startGame
bool cGame::startGame()
{
	// create the window
	GlobalData.windowMain.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT,32),WINDOW_CAPTION,sf::Style::Close);

	// set the target fps
	GlobalData.windowMain.setFramerateLimit(GAME_FPS);

	// load the player resources
	Player.loadResources(&GlobalData);

	// initialize the player
	Player.initialize();

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
		
		if(!paused)
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
		
		// escape key pressed - toggle pause
		if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			paused = !paused;

	}


	// player events
	Player.events();


	return true;
}


// step
void cGame::step()
{
	// Player step
	Player.step();
}

// draw
void cGame::draw()
{
	// clear the window
	GlobalData.windowMain.clear();

	// draw player
	Player.draw();

	// display the painted window
	GlobalData.windowMain.display();
}