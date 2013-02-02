// cInventory.cpp
#include "cInventory.h"




// constructor
cInventory::cInventory()
{
	showing = false;
	slotSelected = 0;
	GlobalData = NULL;
}

// initialize
void cInventory::initialize(cGlobalData* data)
{
	GlobalData = data;

	fnt.loadFromFile("resources/fonts/8-BIT WONDER.TTF");
	fntMain.loadFromFile("resources/fonts/ponde___.ttf");

	templateText.setFont(fnt);



	clear();
}



// events
void cInventory::events(sf::Event& ev)
{
	if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::W && showing)
	{
		// select upwards
		slotSelected --;
		if(slotSelected < 0)
			slotSelected = 0;
	}

	if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::S && showing)
	{
		// select downwards
		slotSelected ++;
		if(slotSelected > INVENTORY_SLOTS-1)
			slotSelected = INVENTORY_SLOTS-1;
	}
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

	// create the inventory string
	std::string invString;
	for(int t= 0; t<INVENTORY_SLOTS; t++)
	{
		std::string addString;

		if(slotSelected == t)
			addString = "> ";
		else
			addString  = "  ";

		if(invData[t].itemIndex >= 0)
		{
			if(invData[t].ammount > 1)
			{
				// plural
				addString += invData[t].ammount;
				addString += " ";
				addString += GlobalData->ITEM_DB[invData[t].itemIndex].name_plural;
			}
			{
				// singular
				addString += GlobalData->ITEM_DB[invData[t].itemIndex].name;
			}
		}
		else
		{
			addString += "empty";
		}



		addString += "\n";
		invString += addString;
	}
	




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
	itemList.setString(invString);//
	GlobalData->windowMain.draw(itemList);

	sf::Text help = templateText;
	help.setColor(sf::Color(130,130,130));
	help.setCharacterSize(12);
	help.setString("Enter to select  W S to move cursor");
	help.setPosition(208,430);
	GlobalData->windowMain.draw(help);

}



// clear
void cInventory::clear()
{
	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		invData[t].itemIndex = -1; // no item
		invData[t].ammount = 0;
	}
}

// itemCount
int cInventory::itemCount(int index)
{
	int count;
	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		if(invData[t].itemIndex == index)
		{
			count += invData[t].ammount;
		}
	}

	return count;
}

// freeSlots
int cInventory::freeSlots()
{
	int count = 0;

	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		if(invData[t].itemIndex < 0)
			count ++;
	}

	return count;
}

// getFirstFreeSlot
int cInventory::getFirstFreeSlot()
{
	if(!freeSlots()>0)
		return -1;

	for(int t=0; t<INVENTORY_SLOTS; t++)
	{
		if(invData[t].itemIndex < 0)
			return t;
	}
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

// give item
bool cInventory::giveItem(int index, int number)
{
	if(hasItem(index))
	{
	}
	else
	{
		invData[getFirstFreeSlot()].itemIndex = index;
		invData[getFirstFreeSlot()].ammount = number;
	}
	return false;
}

// takeItem
bool cInventory::takeItem(int index, int number)
{
	return false;
}