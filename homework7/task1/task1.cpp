#include <iostream>
#include <vector>
using namespace std;
/*ПЛЮС-МИНУС.
Замените в строке каждую четную цифру плюсами,
а нечетную – минусами в количестве равном значению цифры.*/
int getLengthStr(char str[]);
string replacingStr(char numbers[]);
string returnReplacingStr(char number);

int main()
{
	char numbers[] = "123456789";

	cout << replacingStr(numbers);
	
	system("pause");
	return 0;
}

int getLengthStr(char str[]) {
	int counter = 0;

	while (str[counter] != '\0') {
		counter++;
	}

	return counter;
}

string replacingStr(char numbers[]) {
	int sizeStr = getLengthStr(numbers);
	string st;

	for (int i = 0; i < sizeStr; i++) {
		st += returnReplacingStr(numbers[i]);
	}

	return st;
}

string returnReplacingStr(char number) {
	int size = number - '0';
	string str;

	for (int i = 0; i < size; i++) {
		if (size % 2 == 0) {
			str += "+";
		}
		else {
			str += "-";
		}
	}
	str += " ";

	return str;
}