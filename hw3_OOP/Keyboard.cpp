#include "Keyboard.h"

Keyboard::Keyboard(int newprice, std::string manu, std::string color, bool isWireless, int keysNum):
	PeripheralDevice(manu,newprice,color,isWireless),numberOfKeys(keysNum)
{
}

void Keyboard::setNumOfKeys(int newNum)
{
	this->numberOfKeys = newNum;
}

int Keyboard::getNumOfKeys()
{
	return this->numberOfKeys;
}

void Keyboard::connect(Computer* cmp)
{
	std::cout << "Connecting a keyboard" << std::endl;
	std::string str_temp = this->Item::operator std::string();
	std::string str = str_temp;
	if (this->getIsWireless() == true) {
		str = str +" Wireless";
	}
	else {
		str = str + " Wired";
	}
	str = str + ", " + this->getColor() + "," + " Keyboard with " + std::to_string(this->numberOfKeys)+" keys";
	str = str + " is Connecting to computer: ";
	str = str + std::string(*cmp);
	std::cout << str << std::endl;
}

Keyboard::operator std::string() const
{
	std::string ss = "id " + std::to_string(this->getId()) + ": " + this->getManufacturer() +" " + std::to_string(this->getPrice()) + "$" + ",";
	std::string str;
	if (this->getIsWireless() == true)
		str = "Wireless";
	else {
		str = "Wired";
	}
	ss = ss + " " + str + ", " + this->getColor() + "," + " Keyboard with " + std::to_string(numberOfKeys)+" keys";
	return ss;
}


