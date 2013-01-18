#ifndef CPLAYER_H
#define CPLAYER_H

/*
	This class handles the player
*/




// include
#include "cGlobalData.h"
#include <SFML/Graphics.hpp>



// Player physics constants
const float PLAYER_ACCELERATION = 0.2;



// class
class cPlayer
{
private:

	cGlobalData* GlobalData;
	bool keyW, keyA, keyS, keyD;


public:


	cPlayer();

	bool loadResources(cGlobalData* data);

	void initialize();

	void events();
	void step();
	void draw();



	float x, y;
	float xSpeed, ySpeed;



	sf::Texture txtSheet;

	sf::Sprite sprMain;


};


#endif