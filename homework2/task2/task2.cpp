#include <iostream>

using namespace std;

bool isRectangularTriangle(double firstLine, double secondLine, double thirdLine) {
	return firstLine * firstLine == secondLine * secondLine + thirdLine * thirdLine;
}

int main()
{
	double firstLine = 0, secondLine = 0, thirdLine = 0;

	cout << "Please, enter lines of triangle: " << endl;
	cin >> firstLine >> secondLine >> thirdLine;
	firstLine = abs(firstLine);
	secondLine = abs(secondLine);
	thirdLine = abs(thirdLine);

	if (firstLine == 0 || secondLine == 0 || thirdLine == 0) {
		cout << "Error!" << endl;

		return -1;
	}
	else {

	}

	if ((firstLine + secondLine > thirdLine) || secondLine + thirdLine > firstLine || thirdLine + firstLine > secondLine) {
	if (firstLine == secondLine == thirdLine) {
		cout << "this triangle is equilateral" << endl;
	}
	else if (firstLine == secondLine || secondLine == thirdLine || thirdLine == firstLine) {
			if (isRectangularTriangle(firstLine, secondLine, thirdLine) || isRectangularTriangle(secondLine, thirdLine, firstLine) || isRectangularTriangle(thirdLine, firstLine, secondLine)) {
				cout << "this triangle is isosceles and rectangular" << endl;
			}
			else {
		cout << "this triangle is isosceles" << endl;
	}

		}
		else if (isRectangularTriangle(firstLine, secondLine, thirdLine) || isRectangularTriangle(secondLine, thirdLine, firstLine) || isRectangularTriangle(thirdLine, firstLine, secondLine)) {
			cout << "this triangle is of the rectangular from" << endl;
		}
	else {
		cout << "this triangle is of the general form" << endl;
	}
	}
	else {
		cout << "Error" << endl;

		return -1;
	}

}
