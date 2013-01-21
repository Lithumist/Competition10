#ifndef CPROJECTILE_H
#define CPROJECTILE_H

/*
	This class represents a projectile on a map
*/


// include
#include <SFML/Graphics.hpp>
#include "cGlobalData.h"

#include <iostream>




// class
class cProjectile
{
private:
public:

	// GlobalData static member, should be set before any cProjectiles are created
	static cGlobalData* GlobalData;




	float x, y;
	float xSpeed, ySpeed;
	float width, height;
	int dmgPlayer;
	int dmgEnemy;
	float spdRotation;
	sf::Sprite sprite;

	float currentAngle;



	// constructors
	cProjectile();
	cProjectile(float xpos, float ypos, float xspeed, float yspeed, float proj_width, float proj_height, int dmg_player, int dmg_enemy, float rotation_speed, sf::Sprite proj_sprite);

	/*

		Notes:

		xpos and ypos are the centre coordinates, they are NOT the top left!!

		xspeed and yspeed are unit vectors for movement (multiplied by the desired speed of course)

		dmg_player can be set to 0 if you do not want it to damage players (collision check optimisations will be made)
		  - same with dmg_enemy

		rotation_speed is the ammount of degrees that's added to the sprite's rotation every frame

		proj_sprite is assumed to allready be linked to an sf::Texture

	*/


	// loop
	void step(); // moves the projectile but does not check for collisions
	void draw();



};


#endif