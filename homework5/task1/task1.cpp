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
void printingVisibleTerrainProfile(int *mass);

int main()
{
	srand(time(NULL));

	int mass[MASS_SIZE];
	int* fillingMass = fillingInTheArray(mass);

	printingVisibleTerrainProfile(fillingMass);

	system("pause");
	return 0;
}
	
void printingVisibleTerrainProfile(int* mass) {
	cout << mass[0] << "   ";

	int maxNum = 0;

	for (int i = 0; i < MASS_SIZE; i++) {

		if (mass[i] > mass[0] && maxNum < mass[i]) {
			maxNum = mass[i];
			cout << mass[i] << "   ";
		}
	}
}

int* fillingInTheArray(int *mass) {

	for (int i = 0; i < MASS_SIZE; i++) {
		mass[i] = getRandomNumber(0, 20);
	}

	return mass;
}

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}