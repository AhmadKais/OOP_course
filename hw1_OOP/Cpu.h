#pragma once
#include <string>
#include <iostream>

using std::string;

class Cpu
{
private:
	double clockRate;
	string  manufacturerName;
	int yearOfManufacuring;
public:
	//constructor
	Cpu(double cRate = 0, const string name = "~", int year = 0)
		:clockRate(cRate), manufacturerName(name), yearOfManufacuring(year)
	{
	}
	//setters
	void setClockRate(const double cRate);
	void setManufacturer(const string name);
	void setYear(const int year);
	//getters
	double getClockRate() const;
	string getManufacturerName() const;
	int getYearOfManufacurer() const;
	//other functions 
	void print() const;



};

