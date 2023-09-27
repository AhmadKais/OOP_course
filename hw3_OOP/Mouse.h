#pragma once

#include "PeripheralDevice.h"
#include <string>
class Mouse:public PeripheralDevice
{
private: 
	int dpi = 0;
public :
	Mouse(int newPrice,std::string manu, std::string color, bool isWireless, int dpi);
	void setDpi(int newDpi);
	int getDpi();
	virtual void connect(Computer* cmp);
	operator std::string() const override;
};

