#pragma once

#include <string>
#include "Item.h"

#define STORE_SIZE  10

class Branch
{
private: 
	int storeSize = STORE_SIZE;
	Item** items;
	std::string Storelocation = "";
	int itemsNum = 0;
	int oldestIndex = 0;
public:
	Branch(std::string loc = " ", int newsize = STORE_SIZE);
	~Branch();
	Item** getCatalog();
	void addItem(Item* newItem);
	int getStoreSize();
	int getItemsNum();
	void setStoreSize(int size);
	std::string getLocation();
	void setLocation(std::string location);

};

