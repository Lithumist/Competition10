// cGlobalData.cpp
#include "cGlobalData.h"




dbItem makeDbItem(std::string nm, std::string nm_plu, float vl, bool stk, int mx_stk)
{
	dbItem n;

	n.name = nm;
	n.name_plural = nm_plu;
	n.value = vl;
	n.stackable = stk;
	n.max_stack = mx_stk;
	
	return n;
}




// constructor
cGlobalData::cGlobalData()
{
}






// getItem
dbItem cGlobalData::getItem(unsigned int position)
{
	if(position < 0)
	{
		std::cout << "cGlobalData::getItem trying to access an empty inventory slot\n";
	}
}





// pop
void cGlobalData::pop()
{
	// Populate the ITEM_DB vector


	/* 000 */	ITEM_DB.push_back(makeDbItem("coin","coins",1,true,MAX_COIN_STACK));
	/* 001 */	ITEM_DB.push_back(makeDbItem("feather","feather",0.25,true));
	/* 002 */	ITEM_DB.push_back(makeDbItem("stick","sticks",0,true));
	/* 003 */	ITEM_DB.push_back(makeDbItem("stone","stones",0,true));
	/* 004 */	ITEM_DB.push_back(makeDbItem("shiny stone","shiny stones",2,true));

}