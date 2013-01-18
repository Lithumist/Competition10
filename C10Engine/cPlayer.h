#ifndef CPLAYER_H
#define CPLAYER_H

/*
	This class handles the player
*/




// include




// class
class cPlayer
{
private:
public:
	cPlayer();

	void events();
	void step();
	void draw();

	float x, y;
	float xSpeed, ySpeed;


};


#endif