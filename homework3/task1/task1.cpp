#include <iostream>

using namespace std;

double powerNumber(double number, double power);
bool isCurrentPower(double number);

int main()
{
	double number, power;

	cout << "Please, enter number: ";
	cin >> number;
	cout << "and enter power: ";
	cin >> power;

	if (isCurrentPower(power)) {
		cout << powerNumber(number, power);
	}
	else {
		cout << "Incorrect input, please restart program" << endl;
		return -1;
	}
	
	return 0;
}

double powerNumber(double number, double power) {
	for (int i = 1; i < power; i++)	number *= number;

	return number;
}

bool isCurrentPower(double power) {
	return (double)((int)power) == power;
}