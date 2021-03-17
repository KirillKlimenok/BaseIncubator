#include <iostream>

using namespace std;

string enterInputData(string number, string str);
string  printFlipNumber(string number);

int main()
{
	string number = "";

	number = enterInputData(number, "number: ");

	cout << printFlipNumber(number);

	return 0;
}

string enterInputData(string number, string str) {
	cout << "Please, enter " << str;
	cin >> number;
	cout << endl;

	return number;
}

string  printFlipNumber(string number) {
	string flipNumber = "";

	for (int i = number.length(); i > -1; i--) {
		flipNumber += number[i];
	}

	return flipNumber;
}