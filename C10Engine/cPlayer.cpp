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
}


// step
void cPlayer::step()
{
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