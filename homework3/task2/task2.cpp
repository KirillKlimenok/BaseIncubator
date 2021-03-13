#include <iostream>

using namespace std;

void numbersWhoHaveUnitsInBinarySystem(int inputNumber);

int main()
{
	int inputNumber = 0;

	cout << "Please, enter number: ";
	cin >> inputNumber;

	if (!cin) {
		cout << "Input error, please restart programm and try again";
		return -1;
	}
	numbersWhoHaveUnitsInBinarySystem(inputNumber);

	return 0;
}

void numbersWhoHaveUnitsInBinarySystem(int inputNumber) {
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
			else {

			}
		}
	}
}