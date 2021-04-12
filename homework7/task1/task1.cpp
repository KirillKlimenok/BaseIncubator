#include <iostream>
#include <vector>

#define SIZE 256
using namespace std;
/*ПЛЮС-МИНУС.
Замените в строке каждую четную цифру плюсами,
а нечетную – минусами в количестве равном значению цифры.*/
int getLengthStr(char str[]);
string replacingStr(char numbers[]);
string returnReplacingStr(char number);
bool isDigit(char number);

int main()
{
	char numbers[SIZE];

	cout << "Please, enter your liine_: ";
	cin.getline(numbers, SIZE);

	cout << replacingStr(numbers) << endl;
	
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
	string str;

	if (!isDigit(number)) {
		str.push_back(number);
		return str;
	}
	int size = number - '0';
	

	for (int i = 0; i < size; i++) {
		if (size % 2 == 0) {
			str += "+";
		}
		else {
			str += "-";
		}
	}

	return str;
}

bool isDigit(char number) {
	if (number < '0' || number>'9') {
		return false;
	}
	else return true;
}