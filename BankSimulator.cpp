#include "BankSimulator.h"

using namespace std;

int password;
int input;

int main() {
	password = 740165;
	cout << termcolor::red <<"Master" << termcolor::yellow << "Card" << termcolor::reset << endl;

	cout << "Password to Auth: ";
	cin >> input;
	
	if (input != password) {
		cout << termcolor::red << "Password is don't right!" << termcolor::reset << endl;
		system("pause");
		exit(0);
	}
	else {
		menu();
	}

	return 0;
}