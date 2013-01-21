// cMap.cpp
#include "cMap.h"



// constructor
cMap::cMap()
{
	// calculate rectangles
	for(int ypos=0; ypos<44; ypos++)
	{
		for(int xpos=0; xpos<5; xpos++)
		{
			Rectangles[5*ypos+xpos].left	= xpos*32;
			Rectangles[5*ypos+xpos].top		= ypos*32;
			Rectangles[5*ypos+xpos].width	= 32;
			Rectangles[5*ypos+xpos].height	= 32;
		}
	}
}






// loadResources
bool cMap::loadResources(cGlobalData* data)
{
	GlobalData = data;
	cProjectile::GlobalData = data;

	if(!txtGroundSheet.loadFromFile("resources/graphics/ground_sheet.png"))
		return false;

	if(!txtMaskSheet.loadFromFile("resources/graphics/mask_sheet.png"))
		return false;

	if(!txtDefaultProjectile.loadFromFile("resources/graphics/default_projectile.png"))
		return false;

	sprGround.setTexture(txtGroundSheet);
	sprMask.setTexture(txtMaskSheet);
	sprDefaultProjectile.setTexture(txtDefaultProjectile);
	return true;
}







// loadFromFile
// I used goto and idgaf. WAT U GONN DO MOFO?
bool cMap::loadFromFile(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string fileHeader, fileMapName;

	// read the header
	std::getline(file,fileHeader);
	if(fileHeader != MAP_HEADER)
		goto load_fail;

	// read map name
	std::getline(file,fileMapName);
	mapName = fileMapName;

	// prepare for tile reading
	int tile, xpos, ypos;

	// read ground layer
	tile = 0;
	xpos = 0;
	ypos = 0;
	for(int t=0; t<475; t++)  // 25*19 = 475
	{
		file >> tile;

		if(tile<0 || tile > 999)
			goto load_fail;
		else
			layerGround[xpos][ypos] = tile;

		xpos ++;
		if(xpos >= 25)
		{
			xpos = 0;
			ypos ++;
		}
	}

	// read mask layer
	tile = 0;
	xpos = 0;
	ypos = 0;
	for(int t=0; t<475; t++)
	{
		file >> tile;

		if(tile<0 || tile > 999)
			goto load_fail;
		else
			layerMask[xpos][ypos] = tile;

		xpos ++;
		if(xpos >= 25)
		{
			xpos = 0;
			ypos ++;
		}
	}


	// success
	goto load_pass;



load_fail:
	file.close();
	return false;

load_pass:
	file.close();
	return true;
}

// saveToFile
bool cMap::saveToFile(std::string filename)
{
	return true;
}








// events
void cMap::events(sf::Event& ev)
{

	// k key pressed - destroy all projectiles                                  aka, projectile panic key :p
	if(ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::K)
		projectiles.clear();


}


// step
void cMap::step()
{
	// step projectiles
	for(int p=0; p<projectiles.size(); p++)
	{
		projectiles[p].step();
	}
}


// draw
void cMap::draw()
{
	// draw ground
	for(int ypos=0; ypos<19; ypos++)
	{
		for(int xpos=0; xpos<25; xpos++)
		{
			if(!layerGround[xpos][ypos] == 0)
			{

				int tileNumber = layerGround[xpos][ypos];

				sprGround.setTextureRect(Rectangles[tileNumber]);
				sprGround.setPosition((float)(xpos*32),(float)(ypos*32));
				GlobalData->windowMain.draw(sprGround);

			}
		}
	}

	// draw mask
	for(int ypos=0; ypos<19; ypos++)
	{
		for(int xpos=0; xpos<25; xpos++)
		{
			if(!layerMask[xpos][ypos] == 0)
			{

				int tileNumber = layerMask[xpos][ypos];

				sprMask.setTextureRect(Rectangles[tileNumber]);
				sprMask.setPosition((float)(xpos*32),(float)(ypos*32));
				GlobalData->windowMain.draw(sprMask);

			}
		}
	}



	// draw projectiles
	for(int p=0; p<projectiles.size(); p++)
	{
		projectiles[p].draw();
	}

}








// makeProjectile
void cMap::makeProjectile(cProjectile proj)
{
	projectiles.push_back(proj);
}