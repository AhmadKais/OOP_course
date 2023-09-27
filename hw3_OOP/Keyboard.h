#pragma once

#include "PeripheralDevice.h"

class Keyboard: public PeripheralDevice
{
private:
	int numberOfKeys = 0;
public :
	Keyboard(int newprice,std::string manu,std::string color,bool isWireless,int keysNum);
	void setNumOfKeys(int newNum);
	int getNumOfKeys();
	virtual void connect(Computer* cmp);
	operator std::string() const override;
};

