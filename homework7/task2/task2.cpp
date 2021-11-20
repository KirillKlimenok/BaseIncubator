#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#define SIZE 256
using namespace std;

/* ПОЛЕ ЧУДЕС.
Запрограммируйте игру:
открываем буквы, угадываем слово, в конце - шутка Якубовича*/

int getLengthStr(char str[]);
void printStr(char arr[]);
void printSicretWord(bool* guesseds, char hiddenWord[], int size);
bool* clearingTheArray(bool guesseds[], int size);
void start(bool* guesseds, char hiddenWord[], int size);
bool isGuessed(bool* guesseds, int size);
bool* searchLetterInWord(bool guesseds[], int size, char letter, char hiddenWord[]);
void openingCard();
void clearCin();
template <typename T>
T enterData(T data);
bool enterAllWord(bool guesseds[], int size, char hiddenWord[]);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	char hiddenWord[] = "conversation";
	int size = getLengthStr(hiddenWord);
	bool* guesseds = new bool[size];
	guesseds = clearingTheArray(guesseds, size);

	start(guesseds, hiddenWord, size);

	return 0;
}

void start(bool* guesseds, char hiddenWord[], int size) {
	char letter = '\0';
	bool choise = false;
	while (!isGuessed(guesseds, size)) {
		cout << " You can tie it, but you can't untie it. What is it? " << endl;
		printSicretWord(guesseds, hiddenWord,size);

		cout << endl << "Try guess is all word ?" << endl << "enter 1 / 0" << endl;
		choise = enterData(choise);
		clearCin();

		if (choise) {
			clearCin();
			if (enterAllWord(guesseds, size, hiddenWord)) {
				system("CLS");
				cout << "Sicret word: ";
				printSicretWord(guesseds, hiddenWord, size);
				break;
			}
			else {
				cout << "you enterd not true word!" << endl;
				Sleep(300);
			}
		}
		else {
			cout << endl << "Enter your letter_: ";
			letter = enterData(letter);
			clearCin();
			guesseds = searchLetterInWord(guesseds, size, letter, hiddenWord);
		}

		clearCin();
		system("CLS");
	}

	cout << endl << "!!!!!!!!!!!!!" << endl << "WIN" << endl << "!!!!!!!!!!!!!";
}

void clearCin() {
	cin.clear();
	fflush(stdin);
}

template <typename T>
T enterData(T data) {
	cin >> data;
	return data;
}

bool enterAllWord(bool guesseds[], int size, char hiddenWord[]) {
	char* word = new char[size];
	cout << "Enter word: " << endl;
	word = enterData(word);
	bool isTrue = true;
	for (int i = 0; i < size; i++) {
		if (hiddenWord[i] == word[i] || hiddenWord[i] == (char)(word[i] - ' ') || hiddenWord[i] == (char)(word[i] + ' ')) {
			isTrue = true;
		}
		else {
			isTrue = false;
			return isTrue;
		}
	}
	memset(guesseds, true, size);

	return isTrue;
}

bool isGuessed(bool* guesseds, int size) {
	for (int i = 0; i < size; i++) {
		if (!guesseds[i]) {
			return false;
		}
	}
	return true;
}

bool* searchLetterInWord(bool guesseds[], int size, char letter, char hiddenWord[]) {

	for (int i = 0; i < size; i++) {
		if (hiddenWord[i] == letter || hiddenWord[i] == (char)(letter - ' ') || hiddenWord[i] == (char)(letter + ' ')) {
			guesseds[i] = true;
			openingCard();
		}
	}

	return guesseds;
}

bool* clearingTheArray(bool guesseds[], int size) {
	for (int i = 0; i < size; i++) {
		guesseds[i] = false;
	}
	return guesseds;
}

int getLengthStr(char str[]) {

	int counter = 0;

	while (str[counter] != '\0') {
		counter++;
	}

	return counter;
}

void printStr(char arr[]) {
	for (int i = 0; arr[i] != '\n'; i++)	cout << arr[i];
}

void printSicretWord(bool* guesseds, char hiddenWord[], int size) {
	for (int i = 0; i < size; i++) {
		if (guesseds[i]) {
			cout << hiddenWord[i];
		}
		else {
			cout << "*";
		}
	}
}

void openingCard() {
	system("CLS");
	cout << "Opening Card)" << endl;
	for (int i = 0; i < 10; i++) {
		cout << '*';
		Sleep(200);
	}
}