#ifndef CMAP_H
#define CMAP_H

/*
	This class represents the map
*/


// include
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "cGlobalData.h"
#include "cProjectile.h"




// constants
const std::string MAP_HEADER = "C10_MAP";




// class
class cMap
{
private:

	cGlobalData* GlobalData;


public:

	cMap();

	bool loadResources(cGlobalData* data); // also set's cProjectile's GlobalData pointer


	bool loadFromFile(std::string filename);
	bool saveToFile(std::string filename);

	void events(sf::Event& ev);
	void step();
	void draw();

	void drawFrindge();


	void makeProjectile(cProjectile proj);




	std::vector<cProjectile> projectiles;

	std::string warpNorth, warpEast, warpSouth, warpWest;
	std::string mapName;

	sf::IntRect Rectangles[220];

	int layerGround[25][19];
	int layerMask[25][19];
	int layerFrindge[25][19];

	int layerControl[25][19];



	sf::Texture txtGroundSheet;
	sf::Texture txtMaskSheet;
	sf::Texture txtFrindgeSheet;
	sf::Texture txtDefaultProjectile;

	sf::Sprite sprGround;
	sf::Sprite sprMask;
	sf::Sprite sprFrindge;
	sf::Sprite sprDefaultProjectile;



};


#endif