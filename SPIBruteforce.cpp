#include "SPIBruteforce.hpp"

SPIBruteforce& SPIBruteforce::operator= (const SPIBruteforce& unit) {
    this->passwords = unit.passwords;
    return *this;
} 

std::string SPIBruteforce::start (const unsigned short length, const std::string USBPort) {
    while(true) {
        std::string current = "";
        for (int i = 0; i < length; ++i) {
            current += this->alphabet[rand() % length];
        }
        unsigned int lettersCount = 0;
        unsigned int digitsCount = 0;
        for (int i = 0; i < (int)current.size() - 4; ++i) {
            if ((this->digits.find(current[i]) != std::string::npos) && ((current[i] == current[i + 1]) && (current[i] == current[i + 2]) && (current[i] == current[i + 3]))) {
                continue;
            }
        }
        for (int i = 0; i < (int)current.size() - 1; ++i) {
            if ((this->letters.find(current[i]) != std::string::npos) && (this->letters.find(current[i + 1]) != std::string::npos) && (current[i] == current[i + 1])) {
                continue;
            }
            else if (this->letters.find(current[i]) != std::string::npos) {
                ++lettersCount;
            }
            else {
                ++digitsCount;
            }
        }
        if (this->letters.find(current[(int)current.size() - 1]) != std::string::npos) {
            ++lettersCount;
        }
        else {
            ++digitsCount;
        }
        if ((lettersCount < 5) || (digitsCount < 10)) {
            continue;
        }
        else {
            std::ofstream file("key.txt");
            file << current.c_str();
            file.close();
            std::string command = "spiunlock.exe unlock key.txt -usb " + USBPort;
            FILE* pipe = popen(command.c_str(), "r");
            if (!pipe) {
                std::cerr << "Error opening pipe" << std::endl;
                continue;
            }
            char buffer[128];
            bool unlocked = false;
            std::string banWord = "ERROR";
            while (fgets(buffer, 128, pipe) != NULL) {
                if (strstr(buffer, banWord.c_str()) != NULL) {
                    unlocked = false;
                    break;
                }
            }
            if (unlocked) {
                std::cout << "KEY ----> " << current << " ----> UNLOCKING THE CHIP" << std::endl;
                return current;
            } 
            else {
                std::cout << "KEY ----> " << current << " ----> IS WRONG" << std::endl;
            }
            pclose(pipe);
            continue;
        }
    }
}