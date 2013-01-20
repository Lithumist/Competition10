// cMap.cpp
#include "cMap.h"



// constructor
cMap::cMap()
{
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

	// read ground layer
	int tile, xpos, ypos;
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