#include <iostream>

using namespace std;

int enterInputData(int number, string str);
void  flipedNumber(int number);
void printNumber(int number);

int main()
{
	int number = 0;

	number = enterInputData(number, "number: ");

	flipedNumber(number);

	return 0;
}

int enterInputData(int number, string str) {
	cout << "Please, enter " << str;
	cin >> number;
	cout << endl;

	return number;
}

void flipedNumber(int number) {
	do {
		printNumber(number%10);
		number /= 10;
		if (number < 1) {
			break;
		}
	} while (true);
}

void printNumber(int number) {
	cout << number;
}