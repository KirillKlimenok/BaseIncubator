#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>

using namespace std;

// На всякий случай, чтобы не забыть, нужно объявить обозначения меток

#define		L_EMPTY		0
#define		L_KRESTIK   1
#define		L_NOLIK		2

// Поле, 3 на 3. См. выше, чтобы определить принимаемые значения
int field[3][3];

// Выигрышные позиции
int win_pos[5][2] = {
	0,0, 0,2, 2,0, 2,2, 1,1
};

// Массив меток, которые будут ставится в зависимости от значения field
char lab[3] = { '+', 'X', '0' };

int victory = 0;						// Определяет, закончена ли игра
int vp = 0;							// Номер игрока-победителя
int gameOver = 0;						// Никто не выиграл, поле заполнено


void clearField();
int drawField();
int evalSum(int arg[]);
int clearArray(int mass[]);
int findEmpty(int mass[]);
int checkVictory(int mass[]);
int checkPointDanger(int l_pl, int l_comp);
int checkGameOver();
int checkWinPos();
int checkCornPos(int l);
int compStep(int l_pl, int l_comp);
int getRandomNumber(int min, int max);
void moveUser(int type);


int main()
{
	int l_pl = 1;
	int l_comp = 2;
	int tryAgain;
	drawField();
	while (true) {
		int choise;
		cout << "You want move first or second?" << endl << "Enter 1 or 2 _:";
		cin >> choise;

		if (choise == 2) {
			l_pl = 2;
			l_comp = 1;
		}
		else if (choise == 1) {
			l_pl = 1;
			l_comp = 2;
		}

		clearField();
		system("CLS");
		drawField();

		while ((victory == 0) || (gameOver == 0)) {
			if (checkGameOver()) {
				break;
			}

			if (gameOver) break;

			if (choise == 1) {
				moveUser(l_pl);
				//Sleep(2000);
				system("CLS");
				drawField();

				compStep(l_pl, l_comp);
				Sleep(100);
				system("CLS");
				drawField();
			}
			else {
				compStep(l_comp, l_pl);
				system("CLS");
				drawField();

				moveUser(l_pl);
				system("CLS");
				drawField();
			}


		}

		cout << "Do you want try again?" << endl << "Enter 1 or 0: ";
		cin >> tryAgain;
		if (tryAgain == 0) {
			break;
		}

		cin.clear();
		fflush(stdin);
	}

	if (gameOver) printf("Game is over.");
	else if (victory) printf("Player %d has won.", vp);

	system("pause");

	return 0;
}

void clearField() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = 0;
		}
	}

	victory = 0;
	gameOver = 0;
}

void moveUser(int type) {


	int b = 0; // Контроллер цикла
	// Этот цикл - ход компьютера на одну из клеток

	int j;
	// Если все клетки заполнены - выход
	if (checkGameOver()) {
	}
	else {

		int position;
		cout << "Enter your step _: ";
		cin >> position;

		if (position < 0 || position > 9) {
			cout << "Incorrect number !!" << endl;
			system("pause");
			gameOver = 1;
		}
		else {

			switch (position)
			{
			case 9:
			{
				field[0][2] = type;
				break;
			}
			case 6:
			{
				field[1][2] = type;
				break;
			}
			case 3:
			{
				field[2][2] = type;
				break;
			}
			case 8:
			{
				field[0][1] = type;
				break;
			}
			case 5:
			{
				field[1][1] = type;
				break;
			}
			case 2:
			{
				field[2][1] = type;
				break;
			}
			case 7:
			{
				field[0][0] = type;
				break;
			}
			case 4:
			{
				field[1][0] = type;
				break;
			}
			case 1:
			{
				field[2][0] = type;
				break;
			}
			default:
				break;
			}
		}
	}
	cin.clear();
	fflush(stdin);
}


// Процедура, рисующая поле
//
int drawField()
{
	int counter = 0;
	// Цикл по i и j - всего 9 проходов
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Рисуется определенная метка
			cout << " | " << lab[field[i][j]];
			counter++;
			if (counter > 2) {
				cout << " |" << endl << " |-----------|" << endl;
				counter = 0;
			}
		}
	};
	cout << endl;

	return 1;
}

// Процедура, подщитывающая сумму элементов 3-х ячеечного массива
//
int evalSum(int mass[])
{
	int ret = 0;
	for (int i = 0; i < 3; i++) ret += mass[i];
	return ret;
}

// Процедура, приравнивающая все элементы массива к нулю
//
int clearArray(int mass[])
{
	for (int i = 0; i < 3; i++) mass[i] = 0;
	return 0;
}

// Процедура, возвращающая номер нулевого элемента массива
//
int findEmpty(int mass[])
{
	for (int i = 0; i < 3; i++)
		if (mass[i] == 0) return i;
	return -1;
}

// Процедура проверки победы какого-либо игрока
int checkVictory(int mass[])
{
	int ret = 0;
	for (int i = 0; i < 3; i++) ret += mass[i];
	// Если все заполнены, то - победа
	if (ret == 3) { victory = 1; return 1; };
	return 0;
}


int checkPointDanger(int l_pl, int l_comp)
{

	int c[3];
	clearArray(c);
	int p[3];
	clearArray(p);
	int cnt = 0; // Счетчик порядкового номера в линии

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Если рассматриваемая клетка содержит метку, то заполнить соотвествующий массив
			if (field[i][j] == l_pl) p[cnt] = 1;
			if (field[i][j] == l_comp) c[cnt] = 1;
			cnt++; // Следующий элемент линии
		}

		// Проверить, не победил ли кто-либо
		if ((checkVictory(p)) || (checkVictory(c))) return 1;

		// Проверить, нет ли предвыигрышной ситуации
		if ((evalSum(p) == 0) && (evalSum(c) == 2)) {
			int empt = findEmpty(c);
			field[i][empt] = l_comp;
			return 0;
		}

		// Также, только для опасной ситуации
		if ((evalSum(p) == 2) && (evalSum(c) == 0)) {

			int empt = findEmpty(p);
			field[i][empt] = l_comp;
			return 0;
		}

		cnt = 0; // Переход на новую линию
		clearArray(c);
		clearArray(p);

	}

	// Все то же, только для вертикальных линий
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (field[j][i] == l_pl) p[cnt] = 1;
			if (field[j][i] == l_comp) c[cnt] = 1;
			cnt++;
		};
		if ((checkVictory(p)) || (checkVictory(c))) return 1;

		if ((evalSum(p) == 0) && (evalSum(c) == 2)) {
			int empt = findEmpty(c);
			field[i][empt] = l_comp;
			return 0;
		};

		if ((evalSum(p) == 2) && (evalSum(c) == 0)) {

			int empt = findEmpty(p);
			field[empt][i] = l_comp;
			return 0;
		};

		cnt = 0;
		clearArray(c);
		clearArray(p);

	}


	// То же для первой диагонали
	for (int i = 0; i < 3; i++) {
		if (field[i][i] == l_pl) p[cnt] = 1;
		if (field[i][i] == l_comp) c[cnt] = 1;
		cnt++;



		if ((checkVictory(p)) || (checkVictory(c))) return 1;

		if ((evalSum(p) == 0) && (evalSum(c) == 2)) {
			int empt = findEmpty(c);
			field[i][empt] = l_comp;
			return 0;
		}

		if ((evalSum(p) == 2) && (evalSum(c) == 0)) {

			int empt = findEmpty(p);
			field[empt][empt] = l_comp;
			return 0;
		}

		cnt = 0;
		clearArray(c);
		clearArray(p);
	}
	// То же для второй диагонали
	for (int i = 0; i < 3; i++) {
		if (field[i][2 - i] == l_pl) p[cnt] = 1;
		if (field[i][2 - i] == l_comp) c[cnt] = 1;
		cnt++;



		if ((checkVictory(p)) || (checkVictory(c))) return 1;

		if ((evalSum(p) == 0) && (evalSum(c) == 2)) {
			int empt = findEmpty(c);
			field[i][empt] = l_comp;
			return 0;
		}

		if ((evalSum(p) == 2) && (evalSum(c) == 0)) {

			int empt = findEmpty(p);
			field[empt][2 - empt] = l_comp;
			return 0;
		}
	}
	return 1;
}

// Процедура, которая проверяет, не заполнены ли все выигрышные позиции
//
int checkWinPos()
{
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		if (field[win_pos[i][0]][win_pos[i][1]] != 0) cnt++;
	if (cnt == 5) return 0;
	return 1;
}

// Процедура, проверяющая, не заполнено ли все поле
//
int checkGameOver()
{
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (field[i][j] != 0) cnt++;
		}
	}

	if (cnt == 3 * 3) {
		gameOver = 1;
		return 1;
	}
	return 0;
}

// ПроцедураЮ проверяющая возможность построения выигрышной ситуации
//
// Параметры:
// l			- метка игрока
//
int checkCornPos(int l)
{
	// Флаг занятости центральной клетки
	int c = (field[1][1] == 0);

	// Проверка для верхнего края
	// Если две клетки края заняты
	if ((field[0][0] == l) && (field[2][0] == l) && (field[1][0] == 0)) {
		// Проверить первую угловую
		if (field[0][2] == 0) { field[0][2] = l; return 1; }
		// Проверить вторую угловую
		if (field[2][2] == 0) { field[2][2] = l; return 1; }
		// Проверить центральную
		if (c) { field[1][1] = l; return 1; }
	}

	// То же для нижнего края
	if ((field[0][2] == l) && (field[2][2] == l) && (field[1][2] == 0)) {
		if (field[0][0] == 0) { field[0][0] = l; return 1; }
		if (field[2][0] == 0) { field[2][0] = l; return 1; }
	}

	// ... для левго
	if ((field[0][0] == l) && (field[0][2] == l) && (field[0][1] == 0)) {
		if (field[2][0] == 0) { field[2][0] = l; return 1; }
		if (field[2][2] == 0) { field[2][2] = l; return 1; }
		if (c) { field[1][1] = l; return 1; }
	}

	// ... и правого.
	if ((field[2][0] == l) && (field[2][2] == l) && (field[2][1] == 0)) {
		if (field[0][0] == 0) { field[0][0] = l; return 1; }
		if (field[2][0] == 0) { field[2][0] = l; return 1; }
		if (c) { field[1][1] = l; return 1; }
	}

	return 0;
};


int compStep(int l_pl, int l_comp)
{
	// Если кто-то победил, то определить победившего и выйти
	if (victory) { vp = l_comp; return 0; }

	// Первым делом надо проверить на предмет опасных/выигрышных ситуаций
	// Если таковая сложилась, то выйти из процедуры
	if (!checkPointDanger(l_pl, l_comp)) return 0;


	int b = 0; // Контроллер цикла

	// Этот цикл - ход компьютера на одну из клеток
	while (!b) {

		// Если все клетки заполнены - выход
		if (checkGameOver()) break;

		// Если все выигрышные позиции заняты...
		if (!checkWinPos())
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
					if (field[x][y] == 0) {
						// ...походить на первую попавшуюся свободную клетку
						field[x][y] = l_comp;
						return 0;
					};

		// Проверить возможность построения выигрышной ситуации
		if (checkCornPos(l_comp)) return 0;

		int id; // Здесь будет хранится номер выигрышной позиции

		// Получить случайное число.
		// Цикл - для того, чтобы не брать первое попавшееся число цепочки
		for (int i = 0; i < 10; i++) {
			id = (int)(getRandomNumber(0, 5)); // Получили
		};


		// Если больше размера массива, подровнять
		if (id > 4) id = 4;


		// Проверка, не занята ли подобранная позиция

		if (field[win_pos[id][0]][win_pos[id][1]] == 0) {
			field[win_pos[id][0]][win_pos[id][1]] = l_comp; // Заполнить...
			b = 1; // ... и выйти из цикла
		};


		// Цикл будет длиться до тех пор, пока не будет подобрана выигрышная позиция
		// Цикл не может быть бесконечным при правильной работе программы
	};





	return 1;
};

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}