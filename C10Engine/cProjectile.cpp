// cProjectile.cpp
#include "cProjectile.h"

cGlobalData* cProjectile::GlobalData = NULL;



// constructors
cProjectile::cProjectile()
{
	cProjectile(0,0,0,0,16,16,0,0,0,sf::Sprite());
}

cProjectile::cProjectile(float xpos, float ypos, float xspeed, float yspeed, float proj_width, float proj_height, int dmg_player, int dmg_enemy, float rotation_speed, sf::Sprite proj_sprite)
{
	x = xpos;
	y = ypos;
	xSpeed = xspeed;
	ySpeed = yspeed;
	width = proj_width;
	height = proj_height;
	dmgPlayer = dmg_player;
	dmgEnemy = dmg_enemy;
	spdRotation = rotation_speed;
	sprite = proj_sprite;

	sprite.setOrigin(width/2, height/2);

	currentAngle = 0;
}









// step
void cProjectile::step()
{
	// to help with debugging..
	if(GlobalData == NULL)
		std::cout << "God dammit. cProjectile::GlobalData is NULL you fucking retard.\n";

	// move
	x += xSpeed;
	y += ySpeed;

	currentAngle += spdRotation;
}


// draw
void cProjectile::draw()
{
	sprite.setPosition(x,y);
	sprite.setRotation(currentAngle);
	GlobalData->windowMain.draw(sprite);
}