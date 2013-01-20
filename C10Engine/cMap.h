#ifndef CMAP_H
#define CMAP_H

/*
	This class represents the map
*/


// include
#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cGlobalData.h"





// constants
const std::string MAP_HEADER = "C10_MAP";




// class
class cMap
{
private:

	cGlobalData* GlobalData;


public:

	cMap();

	bool loadResources(cGlobalData* data);


	bool loadFromFile(std::string filename);
	bool saveToFile(std::string filename);

	void events();
	void step();
	void draw();





	std::string warpNorth, warpEast, warpSouth, warpWest;
	std::string mapName;

	sf::IntRect Rectangles[220];
	int layerGround[25][19];



	sf::Texture txtGroundSheet;

	sf::Sprite sprGround;


};


#endif