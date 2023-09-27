#pragma once
#include "Cpu.h"
class Computer
{
private:
	Cpu cpu;
	string manufacturerName;
	int yearOfManufacture;
	string color;
	bool isLaptop;
public:
	Computer(const Cpu& cpu = Cpu(), const string manufName = "~", int year = 0, const string clr = "~", bool isLapTop = false)
		: cpu(cpu), manufacturerName(manufName), yearOfManufacture(year), color(clr), isLaptop(isLapTop)
	{
		if (manufName.length() > 10) {
			this->manufacturerName = "~";
		}
		if (clr.length() > 10) {
			this->color = "~";
		}
	}
	//setters
	void setCpu(Cpu cpu);
	void setManufacturer(string name);
	void setYear(int year);
	void setColor(string color);
	void setIsLaptop(bool is);
	//getters
	Cpu getCpu() const;
	string getManufacturerName() const;
	int getYearOfManufacture() const;
	string getColor() const;
	bool getIsLaptop() const;
	//other functions
	void print();

};

