#include "task1.h"

int main()
{
	int firstNumber, secondNumber;

	cout << "Please, enter 2 numbers: ";
	cin >> firstNumber >> secondNumber;

	TheSmallestCommonMultiple multiple;
	cout << multiple.SCM(firstNumber, secondNumber);

	return 0;
}

