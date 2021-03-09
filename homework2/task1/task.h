#include <iostream>
using namespace std;

class TheSmallestCommonMultiple {
private:
	//Euclid's algorithm
	int greatestCommonDivisor(int firstNumber, int secondNumber) {
		if (secondNumber == 0) {
			return firstNumber;
		}
		else {
			greatestCommonDivisor(secondNumber, firstNumber % secondNumber);
		}
	}

public:
	int SCM(int firstNumber, int secondNumber) {
		return (firstNumber * secondNumber) / greatestCommonDivisor(firstNumber, secondNumber);
	}
};
