// cGame.cpp
#include "cGame.h"


// constructor
cGame::cGame()
{
	cGlobalData GlobalData;
	currentState = 0;
	paused = false;
	invPaused = false;
}








// startGame
bool cGame::startGame()
{
	// create the window
	GlobalData.windowMain.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT,32),WINDOW_CAPTION,sf::Style::Close);

	// set the target fps
	GlobalData.windowMain.setFramerateLimit(GAME_FPS);

	// Populate the item database
	GlobalData.pop();

	// load the player resources
	Player.loadResources(&GlobalData);

	// initialize the player
	Player.initialize();

	// load a test map.. for testing
	mapCurrent.loadResources(&GlobalData);
	mapCurrent.loadFromFile("resources/maps/test/test1.txt");

	Player.switchMap(&mapCurrent);

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
		
		if(!paused && !invPaused)
			step();
		else if(invPaused && !paused)
			Player.Inventory.step();
		else if(invPaused && paused)
			1+1;

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

		// toggle inventory
		if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::I)
		{
			if(!paused)
			{
				Player.Inventory.showing = !Player.Inventory.showing;
				invPaused = Player.Inventory.showing;
				Player.Inventory.slotSelected = 0;
		
			}
		}

		// F4 key pressed - take a screenshot and save it
		if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::F4)
		{

			// capture screen
			screenshot = GlobalData.windowMain.capture();

			// get time
			time_t t = time(0);
			tm * now = localtime(&t);

			// format time
			std::string filenm = asctime(now);
			filenm = filenm.substr(0, filenm.size()-1);
			for(std::string::size_type i = 0; (i = filenm.find(":", i)) != std::string::npos;)
			{
				filenm.replace(i, 1, "-");
				i += 1;
			}
			filenm += ".png";

			// save
			if(screenshot.saveToFile("screenshots/" + filenm))
				std::cout << "Screenshot saved to " + filenm + "\n";

		}








		// player events
		Player.events(ev);
		Player.Inventory.events(ev);

		// map events
		mapCurrent.events(ev);


	}


	return true;
}


// step
void cGame::step()
{
	// player step
	Player.step();

	// map step
	mapCurrent.step();
}

// draw
void cGame::draw()
{
	// clear the window
	GlobalData.windowMain.clear();

	// draw map
	mapCurrent.draw();

	// draw player
	Player.draw();

	// draw frindge layer
	mapCurrent.drawFrindge();

	// draw inventory
	if(!paused)
		Player.Inventory.draw();

	// display the painted window
	GlobalData.windowMain.display();
}