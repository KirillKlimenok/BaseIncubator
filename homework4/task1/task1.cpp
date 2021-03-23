#include <iostream>
#include <conio.h>
#include <Windows.h>
/*1) ЧИСЛО СУДЬБЫ.
Цифры полной даты рождения суммируются, пока не получится одна цифра.
Разработайте функцию и вычислите свое число судьбы)*/

using namespace std;

int inputData(int inputData, string str);
int sumNumbers(int number);
int sumNumbersInCurrentData(int firstNumber, int secondNumber, int thirdNumber);
bool isCurrentData(int day, int month, int year);
int sumNumbersInNumber(int number);
bool isCurrentDay(int day);
bool isCurrentMonth(int month);
bool isCurrentYear(int month);

int main()
{

	int day = 0, month = 0, year = 0;
	int theNumberOfFate = 0;

	day = inputData(day, "Day: ");
	
	if (!isCurrentDay(day)) {
		cout << "Incorrect day! " << endl;

		return -1;
	} else{}

	month = inputData(month, "Month: ");
	
	if (!isCurrentMonth(month)) {
		cout << "Incorrect month! " << endl;
		
		return -1;
	} else {}


	year = inputData(year, "year: ");
	
	if (!isCurrentYear(year)) {
		cout << "Incorrect year! " << endl;

		return -1;
	} else {}

	if (isCurrentData(day, month, year)) {
		theNumberOfFate = sumNumbers(sumNumbersInCurrentData(day, month, year));
		cout << "Your fate number: " << theNumberOfFate << endl;
	}
	else {
		system("color 4");
		cout << "Your entered incorrect data" << endl;
		return -1;
	}


	return 0;
}

/*
январь 31, февраль 28/29 каждые четыре года бывает 29, март 31,
апрель 30, май 31, июнь 30, июль 31, август 31, сентябрь 30,
октябрь 31, ноябрь 30, декабрь 31.
*/

bool isCurrentDay(int day) {
	return day > 0 && day < 31;
}

bool isCurrentMonth(int month) {
	return month > 0 && month < 13;
}

bool isCurrentYear(int year) {
	return year > 0 ;
}

bool isCurrentData(int day, int month, int year) {
	if (month < 0 || month > 12 || year < 0) return false;

	if (day > 29 && day <= 31) {
		if ((month % 2 != 0 && month <= 7) || (month >= 8 && month % 2 == 0)) {
			return true;
		}
		else {}
		return false;
	}
	else {}

	if (month == 2) {
		if (day >= 30) return false;
		else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
			return true;
		}
		else return false;
	}
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

	
	number = sumNumbersInNumber(firstNumber) + sumNumbersInNumber(secondNumber) + sumNumbersInNumber(thirdNumber);

	return number;
}

int sumNumbersInNumber(int number) {
	int sum = 0;

	while (true)
	{
		if (number >= 1) {
			sum += number % 10;
			number /= 10;
		}
		else break;
	}
	
	return sum;
}