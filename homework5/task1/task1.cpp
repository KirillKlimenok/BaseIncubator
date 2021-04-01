#include <iostream>
#include <ctime>

#define MASS_SIZE  20

using namespace std;


/*
СИСТЕМА НАБЛЮДЕНИЯ.
В массиве хранятся значения высот профиля местности с постоянным шагом по горизонтали.
Найдите области (точки высот), невидимые для наблюдателя, находящегося в первой точке.
*/

int getRandomNumber(int min, int max);
int* fillingInTheArray(int* mass);
void printingVisibleTerrainProfile(int* mass, bool isVisible);
void printMass(int* mass);

int main()
{
	srand(time(NULL));

	int mass2[] = { 2,1,2,4,3,4,5,2,4,6,7,8,9,1,2,3,10,1,20,21,5 };

	printMass(mass2);

	cout << "Visible point: ";
	printingVisibleTerrainProfile(mass2, true);

	cout << endl << "unvisible points: ";

	printingVisibleTerrainProfile(mass2, false);
	//printingVisibleTerrainProfile(mass2);

	return 0;
}

void printingVisibleTerrainProfile(int* mass, bool isVisible) {
	int maxNum = mass[0];

	for (int i = 0; i < MASS_SIZE; i++) {

		if (mass[0] >= mass[i] && maxNum == mass[0]) {
			if (isVisible) {
				cout << mass[i] << "   ";
			}
		}
		else if (mass[i] > mass[0] && maxNum == mass[0]) {
			maxNum = mass[i];
			if (isVisible) {
				cout << mass[i] << "   ";
			}
		}
		else if (mass[i] >= maxNum) {
			maxNum = mass[i];
			if (isVisible) {
				cout << mass[i] << "   ";
			}
		}
		else {
			if (!isVisible) {
				cout << mass[i] << "   ";
			}
		}
	}
}

void printMass(int* mass) {
	cout << "All points: ";

	for (int i = 0; i < MASS_SIZE; i++) {
		cout << mass[i] << "   ";
	}
	cout << endl;
}