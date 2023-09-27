#include "Computer.h"
#include <string> 

Computer::Computer(int newprice, std::string manufacturer, std::string cpu, bool isnot):
    Item(manufacturer,newprice),isALaptop(isnot),cpuManufacturer(cpu)
{
}

Computer::~Computer()
{
}

void Computer::setCpu(std::string newManufacturer) {
    cpuManufacturer = newManufacturer;
}

std::string Computer::getCpu() const {
    return cpuManufacturer;
}

Computer::operator std::string() const {
    std::string type = isALaptop ? "Laptop" : "Desktop";
    return "id " + std::to_string(getId()) + ": " + getManufacturer() + " " + std::to_string(getPrice()) + "$"", " + type +", " + getCpu();
}
