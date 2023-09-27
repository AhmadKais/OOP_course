#include "Branch.h"

Branch::Branch(std::string loc, int newsize):storeSize(newsize),Storelocation(loc)
{
    items = new Item * [storeSize];
    for (int i = 0; i < storeSize; i++) {
        items[i] = nullptr;
    }
}

Branch::~Branch()
{
    for (int i = 0; i < storeSize; i++) {
        delete items[i];
    }
    delete[] items;
}

Item** Branch::getCatalog()
{
    return this->items;
}

void Branch::addItem(Item* newItem)
{
    if (newItem == nullptr) return;

    if (itemsNum < storeSize) {
        int insertIndex = (oldestIndex + itemsNum) % storeSize;
        items[insertIndex] = newItem;
        itemsNum++;
    }
    else {
        delete items[oldestIndex];
        items[oldestIndex] = newItem;
        oldestIndex = (oldestIndex + 1) % storeSize;
    }
}

int Branch::getStoreSize()
{
    return this->storeSize;
}

int Branch::getItemsNum()
{
    return this->itemsNum;
}

void Branch::setStoreSize(int size)
{
    this->storeSize = size;
}

std::string Branch::getLocation()
{
    return this->Storelocation;
}

void Branch::setLocation(std::string location)
{
    this->Storelocation = location;
}


