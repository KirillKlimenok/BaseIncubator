#include <iostream>

using namespace std;

double returnPowerNumber(double number, double power);
double returnEnteredNumber();
double returnEnteredPower();
bool isCurrentPower(double number);

int main()
{
	double number = returnEnteredNumber(), power = returnEnteredPower();

	if (isCurrentPower(power)) {
		cout << returnPowerNumber(number, power);
	}
	else {
		cout << "Incorrect input, please restart program" << endl;
		return -1;
	}
	
	return 0;
}

double returnPowerNumber(double number, double power) {
	for (int i = 1; i < abs(power); i++)	number *= number;
		
	if (power < 0) return 1 / number;
	else return number;
}

bool isCurrentPower(double power) {
	return (double)((int)power) == power;
}

double returnEnteredNumber() {
	double number = 0;

	cout << "Please, enter number: ";
	cin >> number;

	return number;
}

double returnEnteredPower() {
	double power = 0;

	cout << "Please, enter power: ";
	cin >> power;

	return power;
}