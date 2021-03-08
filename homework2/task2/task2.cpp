#include <iostream>

using namespace std;

int main()
{
	int firstLine = 0, secondLine = 0, thirdLine = 0;

	cout << "Please, enter lines of triangle: " << endl;
	cin >> firstLine >> secondLine >> thirdLine;
	firstLine = abs(firstLine);
	secondLine = abs(secondLine);
	thirdLine = abs(thirdLine);

	if (firstLine == secondLine == thirdLine) {
		cout << "this triangle is equilateral" << endl;
	}
	else if (firstLine == secondLine || secondLine == thirdLine || thirdLine == firstLine) {
		cout << "this triangle is isosceles" << endl;
	}
	else {
		cout << "this triangle is of the general form" << endl;
	}
}
