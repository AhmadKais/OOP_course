#include "Mouse.h"

Mouse::Mouse(int newPrice, std::string manu, std::string color, bool isWireless, int dpi):
	PeripheralDevice(manu, newPrice,color,isWireless),dpi(dpi)
{
}

void Mouse::setDpi(int newDpi)
{
	this->dpi = newDpi;
}

int Mouse::getDpi()
{
	return this->dpi;
}

void Mouse::connect(Computer* cmp)
{
	std::cout << "Connecting a mouse" << std::endl;
	std::string str_temp = this->Item::operator std::string();
	std::string str = str_temp;
	if (this->getIsWireless() == true) {
		str = str +", Wireless";
	}
	else {
		str = str +", Wired";
	}
	str = str + ", " + this->getColor() + "," + " Mouse with dpi : " + std::to_string(this->dpi);
	str = str + " is Connecting to computer: ";
	str = str + std::string(*cmp);
	std::cout << str << std::endl;
}

Mouse::operator std::string() const
{
	std::string ss = "id " + std::to_string(this->getId()) + ": " + this->getManufacturer()+" "+ std::to_string(this->getPrice()) + "$" + ",";
	std::string str_temp = this->Item::operator std::string();
	std::string str = str_temp;
	if (this->getIsWireless() == true)
		str = str + " Wireless";
	else {
		str = str + "Wired";
	}
	ss =str + ", " + this->getColor() + "," + " Mouse with dpi : " + std::to_string(dpi);
	return ss;
}
