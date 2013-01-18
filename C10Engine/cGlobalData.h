#ifndef CGLOBALDATA_H
#define CGLOBALDATA_H

/*
	This class holds all the global data of the game that all classes need to access
*/

//include
#include <SFML/Graphics.hpp>
#include <string>


//class
class cGlobalData
{
private:
public:
	cGlobalData();




	// Window
	sf::RenderWindow windowMain;
};






// CONSTANTS

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 608;
const std::string WINDOW_CAPTION = "C10Engine";
const unsigned int GAME_FPS = 60;




#endif