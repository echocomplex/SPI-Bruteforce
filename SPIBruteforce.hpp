#ifndef SPI_BRUTEFORCE_HPP
#define SPI_BRUTEFORCE_HPP


#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class SPIBruteforce {
private:
    const unsigned short MIN_DIGITS = 10;
    const unsigned short MIN_LETTERS = 5;
    const unsigned short PASSWORD_LENGTH = 32;
    const std::string alphabet = "AaBbCcDdEeFf0123456789";
    const std::string digits = "0123456789";
    const std::string letters = "AaBbCcDdEeFf";
    std::vector <std::string> passwords;

public:
    SPIBruteforce () {}
    SPIBruteforce (const SPIBruteforce& unit) { this->passwords = unit.passwords; }
    SPIBruteforce& operator= (const SPIBruteforce& unit);
    std::string start (const unsigned short length, const std::string USBPort);
};


#endif // SPI_BRUTEFORCE_HPP