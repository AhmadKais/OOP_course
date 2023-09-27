#include "Item.h"

int Item::lastId = 0;

void Item::setPrice(int newprice) {
	this->price = newprice;
}

int Item::getPrice() const{
	return this->price;
}

int Item::getId() const{
	return this->id;
}

std::string Item::getManufacturer() const{
	return this->manufacturer;
}

void Item::setManufacturer(std::string newManufacurer) {
	this->manufacturer = newManufacurer;
}

Item::Item(std::string name, int newprice):manufacturer(name),price(newprice),id(++lastId)
{
}

Item::~Item()
{
	std::cout << "Throwing away an item" << std::endl;
}

Item::operator std::string() const {
	return "id " + std::to_string(id) + ": " + manufacturer + " " + std::to_string(price) + "$";
}
