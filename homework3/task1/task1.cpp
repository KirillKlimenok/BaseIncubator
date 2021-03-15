#include <iostream>

using namespace std;

double returnPowerNumber(double number, double power);
/*double returnEnteredNumber();
double returnEnteredPower();
*/
pair<double, double> inputData();
bool isCurrentPower(double number);

int main()
{
	pair <double, double> input;
	input = inputData();

	if (isCurrentPower(input.first)) {
		cout << returnPowerNumber(input.first, input.second);
	}
	else {
		cout << "Incorrect input, please restart program" << endl;
		return -1;
	}
	
	return 0;
}

double returnPowerNumber(double number, double power) {
	if (power == 0) return 1;

	for (int i = 1; i < abs(power); i++)	number *= number;
		
	if (power < 0) return 1 / number;
	else return number;
}

bool isCurrentPower(double power) {
	return (double)((int)power) == power;
}

pair<double, double> inputData() {
	double number = 0, power = 0;

	cout << "Please, enter number: ";
	cin >> number;
	cout << "and enter power: ";
	cin >> power;

	return {number, power};
}

/*
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
*/