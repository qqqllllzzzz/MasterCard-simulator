#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "include/termcolor.hpp"

std::string generateMasterCard() {
    std::string cardNumber; // ��������� cardNumber ��� ��������� ����������

    // ���������� ������ 2 ����� (51-55)
    int firstTwoDigits = 51 + rand() % 5; // 51, 52, 53, 54 ��� 55
    cardNumber += std::to_string(firstTwoDigits);

    // ���������� ���������� 14 ����
    for (size_t i = 0; i < 14; ++i) {
        cardNumber += std::to_string(rand() % 10); // ��������� ����� �� 0 �� 9
    }

    // �������� ����������� ����� (Luhn algorithm)
    int sum = 0;
    bool alternate = false;
    for(size_t i = cardNumber.length() - 1; i < cardNumber.length(); --i) {
        int n = cardNumber[i] - '0';
        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }
        sum += n;
        alternate = !alternate;
    }

    int checkDigit = (10 - (sum % 10)) % 10;
    cardNumber += std::to_string(checkDigit);

    return cardNumber;
}

void generate() {
    srand(static_cast<unsigned int>(time(0)));

    std::string masterCardNumber = generateMasterCard();
    std::cout << termcolor::bright_yellow << "New MasterCard CashID: " << termcolor::reset << masterCardNumber << std::endl;

    std::ofstream outputFile("accounts/" + masterCardNumber + ".id");

    if (!outputFile) {
        std::cerr << "Error to open file." << std::endl;
        return;
    }

    // ������ ��������� �����
    outputFile << "100" << std::endl;

    outputFile.close();
    std::cout << "Start cash is 100$. This cash has been written." << std::endl;

    std::cout << "Press Enter to return to the main menu..." << std::endl;
    std::cin.ignore(); // �������� ������� ������� Enter
}