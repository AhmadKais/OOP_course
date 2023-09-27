#include <iostream>
#include <fstream>
#include <string>
#include "Cpu.h"
#include "Computer.h"
#include "Store.h"

using std::string;
using std::cout;
using std::endl;


int main()
{
	std::cout << std::boolalpha;
	//freopen("myOutput.txt", "w", stdout); // saving the output to a file named "myOutput.txt" in the project directory;

	Cpu cpu1;
	cpu1.setClockRate(2.4);
	cpu1.setManufacturer("Intel");
	cpu1.setYear(2021);

	Cpu cpu2(3.8, "AMD", 2019);

	Computer computer1;
	computer1.setManufacturer("Apple");
	computer1.setYear(2022);
	computer1.setColor("Silver");
	computer1.setCpu(cpu1);
	computer1.setIsLaptop(false);

	Computer computer2(cpu2, "HP", 2020, "Red", true);

	cout << "Cpu 1 details:" << endl;
	cpu1.print();

	cout << endl << "Computer 2 details:" << endl;
	computer2.print();
	cout << endl << endl;

	cpu1.setManufacturer("I don't remmember if Honda or Toyota");
	cout << endl << endl;

	computer2.setColor("How can I describe colors with word?");
	cout << endl << endl;
	computer2.setColor("Red");

	Store store("A very long name for store! very long!!! very very!!");
	cout << store.getName() << endl;
	store.addComputer(computer1);
	store.addComputer(computer2);
	//i added these 
	//store.printall();
	store.printComputersByYear();

	return 0;
}
