#include <iostream>
/*1) ЧИСЛО СУДЬБЫ.
Цифры полной даты рождения суммируются, пока не получится одна цифра.
Разработайте функцию и вычислите свое число судьбы)*/

using namespace std;

int inputData(int inputData, string str);
int sumNumbers(int number);
int sumNumbersInCurrentData(int firstNumber, int secondNumber, int thirdNumber);

int main()
{

	int day = 0, month = 0, year = 0;
	int theNumberOfFate = 0;

	day = inputData(day, "Day: ");
	month = inputData(month, "Month: ");
	year = inputData(year, "year: ");

	theNumberOfFate = sumNumbers(sumNumbersInCurrentData(day, month, year));

	cout << "Your fate number: " << theNumberOfFate << endl;

	return 0;
}

int inputData(int inputData, string str) {
	cout << "Please, enter " << str;
	cin >> inputData;
	cout << endl;

	return inputData;
}

int sumNumbers(int number) {
	int sum = 0, sumCurrentData = number;

	while (true)
	{
		sum += number % 10;
		number /= 10;

		if (number < 1) {
			if (sum > 10) {
				number = sum;
			}
			else {
				break;
			}
		}
	}

	return sum;
}

int sumNumbersInCurrentData(int firstNumber, int secondNumber, int thirdNumber) {
	int number = 0;

	while (true) {
		if (firstNumber >= 1) {
			number += firstNumber % 10;
			firstNumber /= 10;
		}

		if (secondNumber >= 1) {
			number += secondNumber % 10;
			secondNumber /= 10;
		}

		if (thirdNumber >= 1) {
			number += thirdNumber % 10;
			thirdNumber /= 10;
		}
		else break;
	}

	return number;
}