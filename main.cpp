#include "SPIBruteforce.hpp"
#include <cstdio>
#include <iostream>
#include <string>


int main () {
    std::string USBPort;
    std::cout << "Enter the USB Port ---> ";
    std::cin >> USBPort;
    SPIBruteforce unit;
    std::string key = unit.start(32, USBPort);
    std::cout << std::endl << std::endl << "--- TARGET KEY ----> " << key << std::endl;
    return 0;
}