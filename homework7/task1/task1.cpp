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
	char numbers[] = "12q3ww456ww789";

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

	if (number < '0' || number>'9') {
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