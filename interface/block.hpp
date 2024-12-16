#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void block() {
    std::string cashID;

    std::cout << "Enter CashID for block: ";
    std::cin >> cashID;

    std::string source = "accounts/" + cashID + ".id";  // �������� ����
    std::string destination = "accounts/blocked/" + cashID + ".id";  // ������� ����

    try {
        if (!fs::exists(source)) {
            std::cerr << "Source file does not exist: " << source << std::endl;
            return;
        }

        if (!fs::exists("accounts/blocked")) {
            fs::create_directory("accounts/blocked");
        }

        // �������� ���� � ����� �����
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        // ������� ������������ ����
        fs::remove(source);
        std::cout << "CashID has been blocked." << std::endl;
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}