#include <iostream>

using namespace std;

int massSize = 0;
double sqare = 0;

/*1. ПРОСВЕТ. Куб состоит из n3 прозрачных и непрозрачных кубиков. Имеется ли хотя бы один просвет?*/
int getRandomNumber(int min, int max);
bool isThereAnyClearance(int mass[]);
int* fillingInTheArray();

int main()
{
	int lineCube = 3;
	massSize = pow(lineCube, 3);
	sqare = pow(lineCube, 2);
	int* cube = fillingInTheArray();
	int smalCube = 1;

	if (isThereAnyClearance(cube)) {
		cout << "Yes";
	}
	else {
		cout << "error";
	}


	return 0;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
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

	for (int i = 0; i < sqare; i++) {
		for (int j = i; j < massSize; j += sqare) {
			if (mass[j] == 1) {
				isAnyClearance = true;
			}
			else {
				isAnyClearance = false;
				break;
			}
		}
		if (isAnyClearance == true) break;
	}

	return isAnyClearance;
}