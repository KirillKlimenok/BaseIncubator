#include <iostream>

using namespace std;
int sizeMass;
void printSoldiers(char* soldiers);
char* permutation(char* soldiers);
bool isTrue(char* soldiers);

int main()
{
	char soldiers[] = { '>','<','>','>','<','<','>','>','>','<','<','>','<','>','<','<','>','>','<','<' };
	char* k = soldiers;
	int counter = 1;

	sizeMass = sizeof(soldiers) / sizeof(soldiers[0]);
	
	
	while (!isTrue(k)) {
		k = permutation(k);
		cout << counter << ")  ";
		printSoldiers(k);

		counter++;
	}
	

	

}

void printSoldiers(char* soldiers) {
	for (int i = 0; i < sizeMass; i++) {
		cout << soldiers[i] << " ";
	}
	cout << endl;
}

char* permutation(char* soldiers) {
	for (int i = 0; i < sizeMass; i++) {
		if (soldiers[i] == '>' && soldiers[i + 1] == '<') {
			soldiers[i] = '<';
			soldiers[i + 1] = '>';
		}
	}
	return soldiers;
}

bool isTrue(char* soldiers) {
	for (int i = 0; i < sizeMass; i++) {
		if (soldiers[i] == '>' && soldiers[i + 1] == '<') {
			return false;
		}
	}

	return true;
}
