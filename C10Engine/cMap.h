#ifndef CMAP_H
#define CMAP_H

/*
	This class represents the map
*/


// include
#include <string>
#include <fstream>
#include <iostream>





// constants
const std::string MAP_HEADER = "C10_MAP";




// class
class cMap
{
private:
public:

	cMap();


	bool loadFromFile(std::string filename);
	bool saveToFile(std::string filename);

	std::string warpNorth, warpEast, warpSouth, warpWest;

	std::string mapName;

	int layerGround[25][19];



	sf::Texture txtGroundSheet;

	sf::Sprite sprGround;


};


#endif