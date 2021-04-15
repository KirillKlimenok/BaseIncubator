#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;
int* transparentPoints;
int massSize = 0;
int sqare = 0;

/*1. ПРОСВЕТ. Куб состоит из n3 прозрачных и непрозрачных кубиков. Имеется ли хотя бы один просвет?*/
int getRandomNumber(int min, int max);
bool isThereAnyClearance(int mass[]);
int* fillingInTheArray();
void printCube(int cube[], int linecube);
void printArray(int transparentPoints[]);
bool iscleanseInTopView(int mass[], int lineCube);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int lineCube;

	cout << "Please, enter size cube: ";
	cin >> lineCube;

	massSize = pow(lineCube, 3);
	sqare = pow(lineCube, 2);
	int* cube = fillingInTheArray();
	int smalCube = 1;
	transparentPoints = new int[lineCube];

	printCube(cube, lineCube);

	if (isThereAnyClearance(cube)) {
		cout << "Yes" << endl << "first clearance positions: ";
		printArray(transparentPoints);
	}
	else if (iscleanseInTopView(cube, lineCube)) {
		cout << "Yes" << endl << "first clearance positions: ";
		printArray(transparentPoints);
	}
	else {
		cout << "Error!";
	}


	return 0;
}

void printArray(int transparentPoints[]) {
	for (int i = 0; i < sqrt(sqare); i++) {
		cout << transparentPoints[i] << "  ";
	}
}

void printCube(int cube[], int linecube) {
	int counter = 0;
	double thisSqare = sqare;

	for (int i = 0; i < massSize; i++) {
		if (counter == linecube) {
			cout << endl;
			counter = 0;
		}
		cout << "| " << cube[i] << " | ";
		counter++;


		if (i == thisSqare - 1) {
			cout << "\n";
			thisSqare += sqare;
		}
	}
}

int getRandomNumber(int min, int max)
{
	return 0 + rand() % 2;
}

int* fillingInTheArray() {
	int* cube = new int[massSize];

	for (int i = 0; i < massSize; i++) {
		cube[i] = getRandomNumber(0, 1);
	}

	return cube;
}

bool isThereAnyClearance(int mass[]) {
	bool isAnyClearance = false;
	int counter = 0;
	for (int i = 0; i < sqare; i++) {
		for (int j = i; j < massSize; j += sqare) {
			if (mass[j] == 0) {
				transparentPoints[counter] = j;
				counter++;
				isAnyClearance = true;
			}
			else {
				counter = 0;
				isAnyClearance = false;
				break;
			}
		}
		if (isAnyClearance == true) break;
	}

	return isAnyClearance;
}

bool iscleanseInTopView(int mass[], int lineCube)
{
	bool isTrue = false;
	int counter = 1;
	int cuunterLines = 0;

	for (int i = 0; i < massSize; i += sqare) {
		for (int j = i; j < sqare * cuunterLines; j += lineCube) {

			if (isTrue && counter == lineCube) {
				return true;
			}

			if (mass[j] == 0) {
				isTrue = true;
				transparentPoints[counter] = j;
				counter++;
			}
			else {
				isTrue = false;
				counter = 1;
			}

		}
		cuunterLines++;

	}

	return false;
}