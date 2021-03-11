#include <iostream>

using namespace std;

int main()
{
	double inputNumber = 0.0;

	cout << "Please, enter number: ";
	cin >> inputNumber;

	if (!cin || inputNumber < 0) {
		cout << "Error!";
		return -1;
	}
	else {}

	int number = inputNumber * 10;
	cout << number % 10;

	return 0;
}
