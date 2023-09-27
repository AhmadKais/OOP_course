#pragma once  
#include "Item.h"
#include <string>  

class Computer : public Item {
private:
    std::string cpuManufacturer = "";
    bool isALaptop = false;
public:
    Computer(int newprice , std::string manufacturer, std::string cpu, bool isnot);
    ~Computer();
    void setCpu(std::string newManufacturer);
    std::string getCpu() const; 
    operator std::string() const override; 
};
