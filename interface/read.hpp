#include <iostream>
#include <fstream>
#include <string>
#include "include/termcolor.hpp"

void read() {
    std::cout << "Enter CashID: ";

    std::string inp;
    std::cin >> inp;

    std::ifstream inputFile("accounts/" + inp + ".id");
    std::string line;

    if (!inputFile) {
        std::cerr << "Error when file was tryin' be open." << std::endl;
    }

    std::cout << "\nCash amount: ";

    while (std::getline(inputFile, line)) {
        std::cout << termcolor::green << line << termcolor::reset;
    }
    std::cout << "$\n";

    inputFile.close();
}
