#include <iostream>
#include <string>
#include <fstream>

void updateCash() {
    std::string fileName;
    std::cout << "Enter the file name (without .id): ";
    std::cin >> fileName;

    // Добавляем путь к папке и расширение .id к имени файла
    std::string fullPath = "accounts/" + fileName + ".id";

    // Открываем файл для записи, что очистит его содержимое
    std::ofstream outputFile(fullPath);
    if (!outputFile) {
        std::cerr << "Error: Could not open file " << fullPath << " for writing." << std::endl;
        return;
    }

    // Запрашиваем новый текст у пользователя
    std::string newText;
    std::cout << "Enter new text to write to the file: ";
    std::cin.ignore(); // Игнорируем оставшийся символ новой строки
    std::getline(std::cin, newText); // Считываем весь ввод, включая пробелы

    // Записываем новый текст в файл
    outputFile << newText << std::endl;
    outputFile.close();

    std::cout << "File " << fullPath << " has been updated." << std::endl;
}