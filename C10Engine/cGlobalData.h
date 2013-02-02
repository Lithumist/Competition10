#ifndef CGLOBALDATA_H
#define CGLOBALDATA_H

/*
	This class holds all the global data of the game that all classes need to access
*/

//include
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>





// CONSTANTS

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 608;
const std::string WINDOW_CAPTION = "C10Engine";
const unsigned int GAME_FPS = 60;
const int MAX_COIN_STACK = 999;
const int MAX_DEFAULT_STACK = 10;






// itemDB struct
struct dbItem
{
	std::string name;
	std::string name_plural;
	bool stackable;
	int max_stack;
	float value;
};
dbItem makeDbItem(std::string nm, std::string nm_plu, float vl, bool stk, int mx_stk = MAX_DEFAULT_STACK);






//class
class cGlobalData
{
private:
public:
	cGlobalData();




	// Window
	sf::RenderWindow windowMain;


	// Player coordinates
	float playerX, playerY;


	// Item Database
	std::vector<dbItem> ITEM_DB;
	dbItem getItem(unsigned int position);
	void pop();
};





// USEFUL MACRO

#define CONTROL_IMPASSABLE 1



#endif