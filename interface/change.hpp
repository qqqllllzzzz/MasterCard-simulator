#include <iostream>
#include <string>
#include <fstream>

void updateCash() {
    std::string fileName;
    std::cout << "Enter the file name (without .id): ";
    std::cin >> fileName;

    // ��������� ���� � ����� � ���������� .id � ����� �����
    std::string fullPath = "accounts/" + fileName + ".id";

    // ��������� ���� ��� ������, ��� ������� ��� ����������
    std::ofstream outputFile(fullPath);
    if (!outputFile) {
        std::cerr << "Error: Could not open file " << fullPath << " for writing." << std::endl;
        return;
    }

    // ����������� ����� ����� � ������������
    std::string newText;
    std::cout << "Enter new text to write to the file: ";
    std::cin.ignore(); // ���������� ���������� ������ ����� ������
    std::getline(std::cin, newText); // ��������� ���� ����, ������� �������

    // ���������� ����� ����� � ����
    outputFile << newText << std::endl;
    outputFile.close();

    std::cout << "File " << fullPath << " has been updated." << std::endl;
}