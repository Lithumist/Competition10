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

	if(!txtBowSheet.loadFromFile("resources/graphics/bow_sheet.png"))
		return false;


	return true;
}








// initialize
void cPlayer::initialize()
{
	sprMain.setTexture(txtSheet);
	sprBow.setTexture(txtBowSheet);
	sprBow.setOrigin(16,16);
}






// events
void cPlayer::events(sf::Event& ev)
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


	// update mouse positions
	xMouse = (float)sf::Mouse::getPosition(GlobalData->windowMain).x;
	yMouse = (float)sf::Mouse::getPosition(GlobalData->windowMain).y;
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

	// cap speed
	if(xSpeed > PLAYER_MAX_SPEED)
		xSpeed = PLAYER_MAX_SPEED;
	else if(xSpeed < -PLAYER_MAX_SPEED)
		xSpeed = -PLAYER_MAX_SPEED;

	if(ySpeed > PLAYER_MAX_SPEED)
		ySpeed = PLAYER_MAX_SPEED;
	else if(ySpeed < -PLAYER_MAX_SPEED)
		ySpeed = -PLAYER_MAX_SPEED;

	// calculate friction
	// x
	if(!keyA && !keyD)
	{
		if(xSpeed > 0)
		{
			xSpeed -= PLAYER_FRICTION;
			if(xSpeed < 0)
				xSpeed = 0;
		}
		else if(xSpeed < 0)
		{
			xSpeed += PLAYER_FRICTION;
			if(xSpeed > 0)
				xSpeed = 0;
		}
	}

	// y
	if(!keyW && !keyS)
	{
		if(ySpeed > 0)
		{
			ySpeed -= PLAYER_FRICTION;
			if(ySpeed < 0)
				ySpeed = 0;
		}
		else if(ySpeed < 0)
		{
			ySpeed += PLAYER_FRICTION;
			if(ySpeed > 0)
				ySpeed = 0;
		}
	}


	// add final speeds on
	x += xSpeed;
	y += ySpeed;



	// update player coordinates in cGlobalData
	GlobalData->playerX = x;
	GlobalData->playerY = y;





	// calculate bow angle
	bowAngle = (atan2(yMouse - (y+16), xMouse - (x+16)) *180 /3.14159);
}


// draw
void cPlayer::draw()
{
	// draw the main sprite
	sprMain.setPosition(x,y);
	GlobalData->windowMain.draw(sprMain);

	// draw the rotated bow
	sprBow.setPosition(x+16,y+16); // set bow to centre of player
	sprBow.setRotation(bowAngle); // rotate
	GlobalData->windowMain.draw(sprBow);
}