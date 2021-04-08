#include <iostream>

int cubeSize;

using namespace std;

void printMass(int** mass);

int main()
{
	int** mass;


	cin >> cubeSize;
	mass = new int* [cubeSize];
	for (int i = 0; i < cubeSize; i++) {
		mass[i] = new int[cubeSize];
	}

	mass[cubeSize][cubeSize] = { 0);
	printMass(mass);

	retrun 0;
}

void printMass(int** mass) {
	for (int i = 0; i < cubeSize; i++) {
		for (int j = 0; j < cubeSize; j++) {
			cout << mass[i][j] << "	";
		}
		cout << endl;
	}
}

void checkPoints(int mass[][]) {
	for (int i = 0; i < cubeSize; i++) {
		for (int i = 0; i < cubeSize; i++) {
			if (mass[i][j] == 1) {
				if (isPointsAreAround(i, j)) {
					mass[i][j] = 0;
				}
				else {}
			}
		}
	}
}

bool isPointsAreAround(int i, int j, int mass[][]) {
	int conter = 0;

	for (int i = 0; i < 8; i++) {
		counter + = returnOneIfAroundIsPoint(i, mass);
	}
	if (counter > 3) {
		return true;
	}
	else return false;
}

int returnOneIfAroundIsPoint(int numberAction, int mass[][]) {
	switch (numberAction)
	{
	case 0: {
		if (mass[i + 1][j]) {
			return 1;
		}
		break;
	}
	case 1: {
		if (mass[i - 1][j] && i > 0) {
			return 1;
		}
		break;
	}
	case 2: {
		if (mass[i + 1][j + 1]) {
			return 1;
		}
		break;
	}
	case 3: {
		if (mass[i - 1][j + 1] && i > 1) {
			return 1;
		}
		break;
	}
	case 4: {
		if (mass[i + 1][j - 1] && j > 0) {
			return 1;
		}
		break;
	}
	case 5: {
		if (mass[i - 1][j - 1] && j > 0 && i > 0) {
			return 1;
		}
		break;
	}
	case 6: {
		if (mass[i][j - 1] && j > 0) {
			return 1;
		}
		break;
	}
	case 7: {
		if (mass[i][j + 1]) {
			return 1;
		}
		break;
	}
	default:
		return 0;
		break;
	}

	return 0;
}