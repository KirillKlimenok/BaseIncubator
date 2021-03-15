#include <iostream>

using namespace std;

void printSuitableNumber(int inputNumber);

int returnEnteredNumber();

int main()
{
	int inputNumber = returnEnteredNumber();

	if (!cin) {
		cout << "Input error, please restart programm and try again";
		return -1;
	}
	printSuitableNumber(inputNumber);

	return 0;
}

void printSuitableNumber(int inputNumber) {
	int NumberWithUnits = 7;
	int stepOfBinaryNumbers = 4;

	if (inputNumber < 7) {
		cout << "no numbers";
	}
	else {
		for (int i = 0; i <= inputNumber; i++) {
			if (i == NumberWithUnits) {
				cout << NumberWithUnits << '	';

				NumberWithUnits = NumberWithUnits + stepOfBinaryNumbers * 2;
				stepOfBinaryNumbers *= 2;
			}
			else {}
		}
	}
}

int returnEnteredNumber() {
	int inputNumber;

	cout << "Please, enter number: ";
	cin >> inputNumber;

	return inputNumber;
}