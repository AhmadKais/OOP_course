#include "Computer.h"
#include <iostream>

void Computer::setCpu(Cpu cpu)
{
	this->cpu = cpu;
}

void Computer::setManufacturer(string name)
{
	if (name.length() > 10) {
		std::cout <<"Manufacturer's name length is too long" << std::endl;
		this->manufacturerName = "~";
	}
	this->manufacturerName = name;
}

void Computer::setYear(int year)
{
	this->yearOfManufacture = year;
}

void Computer::setColor(string color)
{
	if (color.length() > 10) {
		std::cout <<"Color string length is too long" << std::endl;
		this->color = "~";
	}
	this->color = color;
}

void Computer::setIsLaptop(bool is)
{
	this->isLaptop = is;
}

Cpu Computer::getCpu() const
{
	return this->cpu;
}

string Computer::getManufacturerName() const
{
	return this->manufacturerName;
}

int Computer::getYearOfManufacture() const
{
	return this->yearOfManufacture;
}

string Computer::getColor() const 
{
	return this->color;
}

bool Computer::getIsLaptop() const
{
	return this->isLaptop;
}

void Computer::print()
{
	this->cpu.print();
	std::cout << "Computer manufacturer: " << this->manufacturerName << std::endl;
	std::cout << "Computer year: " << this->yearOfManufacture << std::endl;
	std::cout << "Computer color: " << this->color << std::endl;
	std::cout << "Computer is laptop: " << this->isLaptop << std::endl;
}
