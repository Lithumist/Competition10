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

	Inventory.initialize(GlobalData);

	Inventory.giveItem(0,100);
	Inventory.giveItem(0,600);
	Inventory.giveItem(1,25);
	Inventory.giveItem(0,9999);
	//Inventory.takeItem(0,60);
}






// switchMap
void cPlayer::switchMap(cMap* newMap)
{
	if(newMap == NULL)
		std::cout << "cPlayer::switchMap being passed a NULL pointer.\n";

	currentMap = newMap;
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
	
	// calculate player tile coordinates
	xTile = (int)((x+16)/32);
	yTile = (int)((y+16)/32);




	// calculate bow angle
	bowAngle = (atan2(yMouse - (y+16), xMouse - (x+16)) *180 /3.14159);



	vtr result;

	// do broad collision check
	//if(currentMap->layerControl[(int)xTile+1][(int)yTile] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(1,0);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile-1][(int)yTile] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(-1,0);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile][(int)yTile+1] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(0,1);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile][(int)yTile-1] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(0,-1);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile+1][(int)yTile+1] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(1,1);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile-1][(int)yTile-1] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(-1,-1);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile+1][(int)yTile-1] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(1,-1);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}
	//if(currentMap->layerControl[(int)xTile-1][(int)yTile+1] == CONTROL_IMPASSABLE)
	//{
		result = handleCollision(-1,+1);
		if(result.collision)
		{
			x += result.x;
			y += result.y;
			xTile = (int)((x+16)/32);
			yTile = (int)((y+16)/32);
		}
	//}







	// update player coordinates in cGlobalData
	GlobalData->playerX = x;
	GlobalData->playerY = y;











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







// handleCollision
vtr cPlayer::handleCollision(int xMod, int yMod)
{
	// check for obvious fail
	if(currentMap->layerControl[(int)(xTile+xMod)][(int)(yTile+yMod)] != CONTROL_IMPASSABLE)
	{
		vtr rtn_obv;
		rtn_obv.collision = false;
		rtn_obv.x = 0;
		rtn_obv.y = 0;
		return rtn_obv;
	}

	// create rectangles
	sf::FloatRect wall;
	sf::FloatRect player;

	wall.left = (xTile+xMod) * 32;
	wall.top = (yTile+yMod) * 32;
	wall.width = 32;
	wall.height = 32;

	player.left = x;
	player.top = y;
	player.width = 32;
	player.height = 32;

	// test for precise collision
	vtr rtn;
	rtn.x = 0;
	rtn.y = 0;

	if(player.intersects(wall))
	{
		rtn.collision = true;
		

		// determine if the collision was vertical or horizontal
		if(xMod != 0)
		{
			rtn.x = -xSpeed;
		}
		else if(yMod != 0)
		{
			rtn.y = -ySpeed;
		}
	}
	else
	{
		rtn.collision = false;
	}

	return rtn;
}










// move
void cPlayer::move(float newX, float newY)
{
	x = newX;
	y = newY;
}