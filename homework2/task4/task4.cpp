#include <iostream>

using namespace std;


int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	int randomNumber = 0, inputNumber = 0;
	bool isRepeat = true;

	while (true) {
		randomNumber = getRandomNumber(1, 10);

		while (true) {
			cout << "Please, enter your number" << endl;
			cin >> inputNumber;

			if (inputNumber > randomNumber) {
				cout << "It's cold, we need a smaller number" << endl;
			}
			else if (inputNumber < randomNumber) {
				cout << "It's cold, we need a higher number" << endl;
			}
			else {
				cout << "Cool, you guessed it" << endl;
				break;
			}
		}

		cout << "Can we play some more ?" << endl;
		cin >> isRepeat;

		if (!isRepeat) {
			break;
		}
		else {
			cin.clear();
			fflush(stdin);
		}

	}
	return 0;
}
