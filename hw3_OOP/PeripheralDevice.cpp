#include "PeripheralDevice.h"

PeripheralDevice::PeripheralDevice(std::string manu, int newPrice,std::string color, bool isWireless):
	color(color),wireless(isWireless),Item(manu,newPrice)
{
}

void PeripheralDevice::setIsWireless(bool isWireless)
{
	this->wireless = isWireless;
}

bool PeripheralDevice::getIsWireless() const
{
	return this->wireless;
}

void PeripheralDevice::setColor(std::string newColor)
{
	this->color = newColor;
}

std::string PeripheralDevice::getColor() const
{
	return this->color;
}

void PeripheralDevice::connect(Computer cmp)
{
	Item* itemStr = this;
	std::cout << std::string(*itemStr) << " " << "is Connecting to computer :" << std::string(cmp) << std::endl;
}

PeripheralDevice::operator std::string() const {
	return "we are currentle in the string() function of the Peripheral Device";
}
