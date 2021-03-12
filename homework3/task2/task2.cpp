#include <iostream>

using namespace std;
//7 15 31 63 127
int main()
{
	int inputNumber = 0;
	int NumberWithUnits = 7;
	int stepOfBinaryNumbers = 4;

	cout << "Please, enter number: ";
	cin >> inputNumber;

	if (!cin) {
		cout << "Input error, please restart programm and try again";
		return -1;
	}

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

	return 0;
}