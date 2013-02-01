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

	fnt.loadFromFile("resources/fonts/8-BIT WONDER.TTF");
	fntMain.loadFromFile("resources/fonts/ponde___.ttf");

	templateText.setFont(fnt);
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
	rct.setPosition(200,152);
	rct.setSize(sf::Vector2f(400,304));
	rct.setFillColor(sf::Color(80,80,80));
	GlobalData->windowMain.draw(rct);

	sf::Text header = templateText;
	header.setColor(sf::Color(150,150,150));
	header.setCharacterSize(30);
	header.setString("Inventory");
	header.setPosition(280,160);
	GlobalData->windowMain.draw(header);

	sf::Text itemList;
	itemList.setFont(fntMain);
	itemList.setCharacterSize(15);
	itemList.setPosition(210,240);
	itemList.setString("  Eye of lal\n  Wutsword\n> 6 Feathers\n  empty\n  empty\n  empty\n  empty\n  empty\n  empty\n  empty");
	GlobalData->windowMain.draw(itemList);

	sf::Text help = templateText;
	help.setColor(sf::Color(130,130,130));
	help.setCharacterSize(12);
	help.setString("Press enter to select");
	help.setPosition(295,430);
	GlobalData->windowMain.draw(help);

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