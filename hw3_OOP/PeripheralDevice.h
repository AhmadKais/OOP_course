#pragma once

#include "Item.h"
#include "Computer.h"
#include <string>  

class PeripheralDevice : public Item
{
private:
	std::string color = "";
	bool wireless = false;
public:
	PeripheralDevice(std::string manu, int newPrice ,std::string color, bool isWireless);
	void setIsWireless(bool isWireless);
	bool getIsWireless() const;
	void setColor(std::string newColor);
	std::string getColor() const;
	virtual void connect(Computer cmp);
	virtual operator std::string() const;
};

