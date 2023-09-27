#pragma once
#include <string>
#include <iostream>

class Item
{
private:
	int price = 0;
	std::string manufacturer = "";
	const int id;
	static int lastId;
public:
	Item(std::string name = "", int price = 0);
	virtual ~Item();
	void setPrice(int newprice);
	int getPrice() const;
	int getId() const;
	std::string getManufacturer() const;
	void setManufacturer(std::string newManufacurer);
	virtual operator std::string() const;

};

