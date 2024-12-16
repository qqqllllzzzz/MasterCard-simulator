#include <iostream>
#include <filesystem>
#include "include/termcolor.hpp"

void ActiveCards() {
    namespace fs = std::filesystem;

    std::cout << "\n\nList of valid CashID's" << std::endl;

    // Указываем путь к папке "accounts"
    fs::path accountsPath = fs::current_path() / "accounts";

    // Проверяем, существует ли директория
    if (!fs::exists(accountsPath) || !fs::is_directory(accountsPath)) {
        std::cerr << "Directory 'accounts' or 'blocked' not found." << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(accountsPath)) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            std::size_t lastDot = filename.find_last_of('.');

            if (lastDot != std::string::npos) {
                filename = filename.substr(0, lastDot);
            }

            std::cout << termcolor::green << filename << termcolor::reset << std::endl;
        }
    }
}
void BlockedCards() {
    namespace fs = std::filesystem;

    std::cout << "\n\nList of blocked CashID's" << std::endl;

    // Указываем путь к папке "accounts/blocked"
    fs::path accountsPath = fs::current_path() / "accounts/blocked";

    // Проверяем, существует ли директория
    if (!fs::exists(accountsPath) || !fs::is_directory(accountsPath)) {
        std::cerr << "Directory 'accounts' or 'blocked' not found." << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(accountsPath)) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            std::size_t lastDot = filename.find_last_of('.');

            if (lastDot != std::string::npos) {
                filename = filename.substr(0, lastDot);
            }

            std::cout << termcolor::red << filename << termcolor::reset << std::endl;
        }
    }
}