#include <iostream>

using namespace std;

int main()
{
	int nFibonachi = 0, counter = 0;
	int inputNumber = 0;
	int mass[2];

	mass[0] = 0;
	mass[1] = 1;

	cout << "Please, enter number element: ";
	cin >> inputNumber;

	while (true) {
		if (counter == inputNumber - 1) {
			cout << nFibonachi;
			break;
		}

		counter++;

		mass[0] = mass[1];
		mass[1] = nFibonachi;

		nFibonachi = mass[0] + mass[1];
	}

	return 0;
}