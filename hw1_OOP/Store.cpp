#include "Store.h"
#include <iostream>

const string Store::getName()
{
	return this->storeName;
}

const int Store::getComputersNum()
{
	return this->computersNum;
}

const Computer* Store::getComputers()
{
	return this->computers;
}

void Store::setName(const string name)
{
	if (name.length() > 10) {
		this->storeName = "~";
		std::cout << "Store's name length is too long" << std::endl;
	}
	else {
		this->storeName = name;
	}
}

void Store::setComputersNum(const int num)
{
	this->computersNum = num;
}

void Store::setComputers(const Computer Computers[])
{
	for (int i = 0; i < MAX_COMPUTERS_NUMBER; i++) {
		this->computers[i] = Computers[i];
	}
}

void Store::addComputer(const Computer& computer)
{
	if (this->computersNum == MAX_COMPUTERS_NUMBER) {
		std::cout << "The store is full!" << std::endl;
	}
	else {
		this->computers[this->computersNum] = computer;
		this->computersNum++;
	}
}

void Store::printComputersByName()
{
	Computer cmptr;
	for (int i = this->computersNum-1;i >= 0; i--) {
		for (int j = 0;j < i; j++) {
			if (this->computers[j].getManufacturerName() >
				this->computers[j + 1].getManufacturerName()) {
				cmptr = this->computers[j+1];
				this->computers[j + 1] = this->computers[j];
				this->computers[j] = cmptr;
			}
		}
	}
	std::cout << "There are " << this->computersNum << " computers in the store. The computers: " << std::endl;
	for (int i = 1; i <= this->computersNum; i++) {
		std::cout << "Computer " << i << std::endl;
		this->computers[i-1].print();
		std::cout << std::endl;
	}
}

void Store::printComputersByYear()
{
	Computer cmptr;
	for (int i = this->computersNum-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (this->computers[j].getYearOfManufacture() >
				this->computers[j + 1].getYearOfManufacture()) {
				cmptr = this->computers[j + 1];
				this->computers[j + 1] = this->computers[j];
				this->computers[j] = cmptr;
			}
		}
	}
	std::cout << "There are " << this->computersNum << " computers in the store. The computers: " << std::endl;
	for (int i = 1; i <= this->computersNum; i++) {
		std::cout << "Computer " << i << std::endl;
		this->computers[i-1].print();
		std::cout <<std::endl;
	}
}

void Store::printall()
{
	for (int i = 0; i < this->computersNum; i++) {
		this->computers[i].print();
	}
}
