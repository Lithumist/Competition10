// cInventory.cpp
#include "cInventory.h"




// constructor
cInventory::cInventory()
{
	showing = false;
	GlobalData = NULL;
}

// initialize
void cInventory::initialize(cGlobalData* data)
{
	GlobalData = data;
}



// events
void cInventory::events(sf::Event& ev)
{
}

// step
void cInventory::step()
{
	if(!showing)
		return;
}

// draw
void cInventory::draw()
{
	if(!showing)
		return;

	sf::RectangleShape rct;
	rct.setPosition(200,200);
	rct.setSize(sf::Vector2f(400,200));
	rct.setFillColor(sf::Color(80,80,80));
	GlobalData->windowMain.draw(rct);
}



// clear
void cInventory::clear()
{
	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		invData[t].itemIndex = -1; // no item
	}
}

// itemCount
int cInventory::itemCount(int index)
{
	int count;
	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		if(invData[t].itemIndex == index)
			count ++;
	}

	return count;
}

// hasItem
bool cInventory::hasItem(int index)
{
	bool has = false;
	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		if(invData[t].itemIndex == index)
			has = true;
	}

	return has;
}