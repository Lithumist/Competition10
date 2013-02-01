#ifndef CPLAYER_H
#define CPLAYER_H

/*
	This class handles the player
*/




// include
#include "cGlobalData.h"
#include <SFML/Graphics.hpp>
#include "cMap.h"
#include "cInventory.h"



// Player physics constants
const float PLAYER_ACCELERATION = (float)0.6;
const float PLAYER_MAX_SPEED = (float)4;
const float PLAYER_FRICTION = (float)0.4;


struct vtr { float x; float y; bool collision; };


// class
class cPlayer
{
private:

	cGlobalData* GlobalData;
	cMap* currentMap;
	bool keyW, keyA, keyS, keyD;


public:


	cPlayer();

	bool loadResources(cGlobalData* data);

	void initialize();

	void switchMap(cMap* newMap);

	void events(sf::Event& ev);
	void step();
	void draw();

	vtr handleCollision(int xMod, int yMod);

	void move(float newX, float newY);




	cInventory Inventory;


	float x, y, xTile, yTile;
	float xSpeed, ySpeed;
	float xMouse, yMouse;
	float bowAngle;



	sf::Texture txtSheet;
	sf::Texture txtBowSheet;

	sf::Sprite sprMain;
	sf::Sprite sprBow;


};


#endif