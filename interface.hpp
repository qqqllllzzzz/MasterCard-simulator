#include "interface/cashid.hpp"
#include "interface/define.h"
#include "include/termcolor.hpp"
#include "interface/read.hpp"
#include "interface/list.hpp"
#include "interface/change.hpp"
#include "interface/block.hpp"
#include <string>

void PrintMenu() {
	std::cout << termcolor::red << "Master" << termcolor::yellow << "Card" << termcolor::reset << " System\n";
	std::cout << SB"Create CashID (cid)" << "\n";
	std::cout << SB"Check Cash on CashID (ccid)" << "\n";
	std::cout << SB"List of CashID's (lcid - Valid cards & bid - blocked card's)" << "\n";
	std::cout << SB"Change Amount of Money (cmid)" << "\n";
	std::cout << SB"Block CashID (bcid)" << "\n";
	std::cout << SB"Clear window (reset)" << "\n";
}

void menu() {
	system("cls");
	PrintMenu();

	while (1) {
		std::string ch;
		std::cin >> ch;

		if (ch == cid) {
			generate();
		}
		if (ch == ccid) {
			read();
		}
		if (ch == list) {
			ActiveCards();
		}
		if (ch == blocklist) {
			BlockedCards();
		}
		if (ch == change) {
			updateCash();
		}
		if (ch == blockcard) {
			block();
		}
		if (ch == res) {
			system("cls");
			PrintMenu();
		}
	}

}

void cash() {
	
}