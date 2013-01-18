//cPlayer.cpp
#include "cPlayer.h"



// constructor
cPlayer::cPlayer()
{
	x = 0;
	y = 0;
	xSpeed = 0;
	ySpeed = 0;
}







// loadResources
bool cPlayer::loadResources(cGlobalData* data)
{
	GlobalData = data;

	if(!txtSheet.loadFromFile("resources/graphics/player_sheet.png"))
		return false;


	return true;
}








// initialize
void cPlayer::initialize()
{
	sprMain.setTexture(txtSheet);
}






// events
void cPlayer::events()
{
	// update key states
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		keyW = true;
	else
		keyW = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		keyA = true;
	else
		keyA = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		keyS = true;
	else
		keyS = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		keyD = true;
	else
		keyD = false;
}


// step
void cPlayer::step()
{
	// add movement
	if(keyW)
		ySpeed += -PLAYER_ACCELERATION;
	if(keyA)
		xSpeed += -PLAYER_ACCELERATION;
	if(keyS)
		ySpeed += PLAYER_ACCELERATION;
	if(keyD)
		xSpeed += PLAYER_ACCELERATION;


	// add final speeds on
	x += xSpeed;
	y += ySpeed;
}


// draw
void cPlayer::draw()
{
	// draw the main sprite
	sprMain.setPosition(x,y);
	GlobalData->windowMain.draw(sprMain);
}