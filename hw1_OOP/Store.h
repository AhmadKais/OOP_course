#pragma once
#include <string>
#include "Computer.h"

#define MAX_COMPUTERS_NUMBER 10

class Store
{
private:
	string storeName;
	Computer computers[MAX_COMPUTERS_NUMBER];
	int computersNum;
public:
    Store(const std::string& name = "~" , const Computer computers[] = NULL, const int computersNum = 0)
        : storeName(name), computersNum(computersNum)
    {   
        if (this->storeName.length() > 10) {
            std::cout << "Store's name length is too long" << std::endl;
            this->storeName = "~";
        }
        if (computers == NULL) {
            return;
        }
        // Copy the computers from the passed array to the member array
        for (int i = 0; i < computersNum; ++i) {
            this->computers[i] = computers[i];
        }
    }
    
    //getters
    const string getName();
    const int getComputersNum();
    const Computer* getComputers();
    
    //setters
    void setName(const string name);
    void setComputersNum(const int num);
    void setComputers(const Computer Computers[]);
    
    //other functions
    void addComputer(const Computer& computer);
    void printComputersByName();
    void printComputersByYear();
    void printall();
};

