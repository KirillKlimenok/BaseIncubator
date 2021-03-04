#include <iostream>

using namespace std;

int main()
{
	int binaryNumber = 0;
	int decimalNumber = 0;
	int counter = 0;

	cout << "Please, enter decimal number: ";
	cin >> binaryNumber;

	if (binaryNumber < 0) return -1;

	do {
		decimalNumber += binaryNumber % 10 * pow(2, counter);
		binaryNumber /= 10;

		counter++;

		if (binaryNumber < 0.1) break;

	} while (true);

	cout << decimalNumber;

	return 0;
}