#include "Cpu.h"
#include <iostream> 
void Cpu::setClockRate(const double cRate)
{
	if (cRate < 0) {
		this->clockRate = 0;
	}
	else{
		this->clockRate = cRate;
	}
}

void Cpu::setManufacturer(const string name)
{	
	if (name.length() <= 10) {
		this->manufacturerName = name;
	}
	else {
		std::cout << "Manufacturer's name length is too long" << std::endl;
		this->manufacturerName = "~";
	}
}

void Cpu::setYear(const int year)
{
	if (year < 0) {
		this->yearOfManufacuring = 0;
	}
	else {
		this->yearOfManufacuring = year;
	}
}

double Cpu::getClockRate() const
{
	return this->clockRate;
}

string Cpu::getManufacturerName() const
{
	return this->manufacturerName;
}

int Cpu::getYearOfManufacurer() const
{
	return this->yearOfManufacuring;
}

void Cpu::print() const
{
	std::cout << "Cpu clockRate: " << this->clockRate << std::endl;
	std::cout << "Cpu manufacturer: " << this->manufacturerName << std::endl;
	std::cout << "Cpu year: " << this->yearOfManufacuring << std::endl;

}
