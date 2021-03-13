#include <iostream>

using namespace std;

int fabonachiNumber(int number);

int main()
{
	int inputNumber = 0;

	cout << "Please, enter number element: ";
	cin >> inputNumber;

	if (!cin || inputNumber < 1) {
		cout << "input error, please try again!" << endl;
		return -1;
	}

	cout << fabonachiNumber;

	return 0;
}

int fabonachiNumber(int number) {
	int mass[2];
	int nFibonachi = 0, counter = 0;

	mass[0] = 0;
	mass[1] = 1;

	while (true) {
		if (counter == inputNumber - 1) {
			return nFibonachi;
			break;
		}

		counter++;

		mass[0] = mass[1];
		mass[1] = nFibonachi;

		nFibonachi = mass[0] + mass[1];
	}
}