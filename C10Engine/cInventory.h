#ifndef CINVENTORY_H
#define CINVENTORY_H

/*
	This class represents the playey's inventory
*/



// include
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cGlobalData.h"





const unsigned int INVENTORY_SLOTS = 8;






struct sInventorySlot
{
	int itemIndex;
};





class cInventory
{
private:

	cGlobalData* GlobalData;

public:

	cInventory();

	void initialize(cGlobalData* data);

	void events(sf::Event& ev);
	void step();
	void draw();


	void clear();
	int itemCount(int index);
	bool hasItem(int index);




	bool showing;

	sInventorySlot invData[INVENTORY_SLOTS];

	sf::Font fnt;
	sf::Font fntMain;
	sf::Text templateText;




};




#endif