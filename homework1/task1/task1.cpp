#include <iostream>

using namespace std;

int main()
{
	int nMutants = 0, dayCounter = 0;
	short procentInNight = 0;
	int killInDay = 0;
	bool isDayOrNight = true;

	cout << "Please enter number of mutants: ";
	cin >> nMutants;
	cout << endl << "Please enter procent in night: ";
	cin >> procentInNight;
	cout << endl << "Please enter numbers kills in day: ";
	cin >> killInDay;

	if (nMutants == killInDay) {
		cout << "Human win" << endl << "days for kills mutants: " << dayCounter;
		return 0;
	}

	if (nMutants * procentInNight / 100 > killInDay) {
		cout << "Mutants win";
		return 0;
	}

	while (true) {
		if (isDayOrNight) {
			nMutants -= killInDay;
			if (nMutants == 0 || nMutants < 0) {
				cout << "Human win" << endl << "Days: " << dayCounter;
				break;
			}
			isDayOrNight = false;
		}

		if ((nMutants * procentInNight / 100) > (killInDay) && (dayCounter == 1)) {
			cout << "Mutants win";
			return 0;
		}
		else {
			nMutants += nMutants * procentInNight / 100;
			isDayOrNight = true;
			dayCounter++;
		}

	}

	return 0;
}