#include <iostream>

using namespace std;
//7 15 31 63 127
int main()
{
	int inputNumber = 0;
	int x = 7;
	int a = 4;

	cin >> inputNumber;

	for (int i = 0; i <= inputNumber; i++) {
		if (i == x) {
			cout << x << '	';
			x = x + a * 2;
			a *= 2;
		}
		else {

		}
	}

	return 0;
}