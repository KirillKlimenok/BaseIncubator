#include "task1.h"

int main()
{
	int firstNumber, secondNumber;

	cout << "Please, enter 2 numbers: ";
	cin >> firstNumber >> secondNumber;

	TheSmallestCommonMultiple multiple;
	cout << multiple.SCM(abs(firstNumber), abs(secondNumber));

	return 0;
}

