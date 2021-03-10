#include <iostream>

using namespace std;


int greatestCommonDivisor(int firstNumber, int secondNumber) {
	if (secondNumber == 0) {
		return firstNumber;
	}
	else {
		greatestCommonDivisor(secondNumber, firstNumber % secondNumber);
	}
}

int scm(int firstNumber, int secondNumber) {
	return (firstNumber * secondNumber) / greatestCommonDivisor(firstNumber, secondNumber);
}

int main()
{
	int firstNumber = 0, secondNumber = 0;

	cout << "please, enter two numbers to calculate the smallest common multiple: " << endl;
	cin >> firstNumber >> secondNumber;

	if (!cin){
		cout << "Error!";
		return -1;
	}
	else {}

	cout << scm(firstNumber, secondNumber);

	return 0;
}
