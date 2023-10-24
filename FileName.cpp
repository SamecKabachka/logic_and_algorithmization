#include <Windows.h> // для русификации
#include <iostream> // для using namespace std; cout; cin;
#include <cstdlib> // очистка демонической памяти святой водой
#include <time.h> // для секундомера
#include <stdlib.h> // для бастрой сортировки qsort

using namespace std;
void menu();
void task1();
void Shell();
void QuickSort();
void quicksort(int*, int, int);
void QuickSort2();
int comp(const void*, const void*);
int n;

void main() {

	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "              Доброго времяни суток пользователь программы!!!" << endl
		<< "Эта программа преднозначена для заполнения одинаковых квадратных двумерных" << endl
		<< "массивов  случайными  числами  и  последующее  их  перемножение  на  время," << endl
		<< "а также для сравнения быстродействия сортировки Шелла и быстрой сортировки." << endl;
	system("pause");
	system("cls");

	menu();

	while (n != 0) {
		switch (n) {
		case 1:
			task1();

			system("pause");
			system("cls");
			menu();
			break;
		case 2:
			Shell();

			system("pause");
			system("cls");
			menu();
			break;
		case 3:
			QuickSort();

			system("pause");
			system("cls");
			menu();
			break;
		case 4:
			QuickSort();

			system("pause");
			system("cls");
			menu();
			break;
		default:
			cout << "Неправильно выбран пункт меню!" << endl;

			system("pause");
			system("cls");
			menu();
			break;
		}
	}
}
void menu() {
	cout << "Выберете пинкт меню:" << endl
		<< "(1) Создать массивы;" << endl
		<< "(2) Сортировка Шелла;" << endl
		<< "(3) Быстроя сортировка;" << endl
		<< "(4) Быстроя сортировка 2;" << endl
		<< "(0) Выход из программы." << endl
		<< "Ваш выбор: ";
	cin >> n;
	system("cls");
}
void task1() {
	int a, max = 100, min = 0;
	cout << "Квадратная матрица n-го порядка." << endl
		<< "n = ";
	cin >> a;

	int **matrix0, **matrix1, **matrix2; // матрица это миф!!!
	matrix0 = new int *[a]; // массив заполненный указателями
	matrix1 = new int *[a]; // длинна массива = кол-во строк
	matrix2 = new int *[a];
	for (int i = 0; i < a; i++) {
		matrix0[i] = new int[a]; // массивы готовые к работе
		matrix1[i] = new int[a]; // длинна массива = кол-ву столбцов
		matrix2[i] = new int[a];
	}
	clock_t start, end;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			matrix1[i][j] = min + rand() % (max - min + 1);
			matrix2[i][j] = min + rand() % (max - min + 1);
		}
	}
	start = clock();
	for (int i = 0, c = 0; i < a; i++) {
		for (int j = 0; j < a; j++, c++) {
			matrix0[i][j] = 0;
			for (int b = 0; b < a; b++) {
				matrix0[i][j] += matrix1[i][b] * matrix2[b][j];
			}
			cout << "[" << i +1 << "]" << "[" << j + 1 << "]: "
				<< "[" << matrix0[i][j] << "]\t";
			if (c % 3 == 2) {
				cout << endl;
			}
		}
	}
	end = clock();
	cout << endl << "Программа закончила считать матрицы [" << a << "]["
		<< a << "] за " << (end - start) /*/ CLK_TCK*/ << " секунд." << endl;
	free(matrix0);
	free(matrix1);
	free(matrix2);
}
void Shell() {
	int count, e, max = 100, min = 0;
	cout << "Укажите размер массива: ";
	cin >> count;

	int *items = new int[count];
	clock_t start, end;

	cout << "Укажите как заполнить массив:" << endl
		<< "(1) Рандомными значениями;" << endl
		<< "(2) Возрастающими значениями;" << endl
		<< "(3) Убывающими значениями;" << endl
		<< "(4) Половина возрастающими, половина уменьшающими." << endl
		<< "Ваш выбор: ";
	cin >> e;

	switch (e) {
	case 1:
		for (int i = 0; i < count; i++) {
			items[i] = min + rand() % (max - min + 1);
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			items[i] = i + 1;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			items[i] = count - i;
		}
		break;
	case 4:
		for (int i = 0, j = count / 2; i < count; i++) {
			if (i < j) {
				items[i] = i;
			}
			if (i >= j) {
				items[i] = count - i;
			}
		}
		break;
	}
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	start = clock();
	for (int i = 5; i > 0; i--) { // радуга, постепенно укорачивается
		for (int j = 0; j < i; j++) { // шаг в перёд радуг
			for (int b = i + j; b < count; b += i) { // количество радуг
				for (int c = b - i; c >= 0 and items[c] > items[c + i]; c -= i) { // сравнение чисел
					swap(items[c], items[c + i]); // меняем местами если нужно
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	cout << endl;
	end = clock();
	cout << "Программа закончила сортировку по методу Шелла за "
		<< (end - start) /*/ CLK_TCK*/ << " секунд." << endl;
	free(items);
}
void QuickSort() {
	int count, e, max = 100, min = 0;
	cout << "Укажите размер массива: ";
	cin >> count;

	int* items = new int[count];
	clock_t start, end;

	cout << "Укажите как заполнить массив:" << endl
		<< "(1) Рандомными значениями;" << endl
		<< "(2) Возрастающими значениями;" << endl
		<< "(3) Убывающими значениями;" << endl
		<< "(4) Половина возрастающими, половина уменьшающими." << endl
		<< "Ваш выбор: ";
	cin >> e;

	switch (e) {
	case 1:
		for (int i = 0; i < count; i++) {
			items[i] = min + rand() % (max - min + 1);
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			items[i] = i + 1;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			items[i] = count - i;
		}
		break;
	case 4:
		for (int i = 0, j = count / 2; i < count; i++) {
			if (i < j) {
				items[i] = i;
			}
			if (i >= j) {
				items[i] = count - i;
			}
		}
		break;
	}
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	start = clock();
	///////////////////////////////////////////////////////////////
	int left, right;
	left = 0;
	right = count - 1;
	quicksort(items, left, right);
	///////////////////////////////////////////////////////////////
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	cout << endl;
	end = clock();
	cout << "Программа закончила сортировку по методу Шелла за "
		<< (end - start) /*/ CLK_TCK*/ << " секунд." << endl;
	free(items);
}
void quicksort(int* items, int left, int right) {
	int i = left;
	int j = right;
	int tmp;
	int pivot = items[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (items[i] < pivot)
			i++;
		while (items[j] > pivot)
			j--;
		if (i <= j) {
			tmp = items[i];
			items[i] = items[j];
			items[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quicksort(items, left, j);
	if (i < right)
		quicksort(items, i, right);
}
void QuickSort2() {
	int count, e, max = 100, min = 0;
	cout << "Укажите размер массива: ";
	cin >> count;

	int* items = new int[count];
	clock_t start, end;

	cout << "Укажите как заполнить массив:" << endl
		<< "(1) Рандомными значениями;" << endl
		<< "(2) Возрастающими значениями;" << endl
		<< "(3) Убывающими значениями;" << endl
		<< "(4) Половина возрастающими, половина уменьшающими." << endl
		<< "Ваш выбор: ";
	cin >> e;

	switch (e) {
	case 1:
		for (int i = 0; i < count; i++) {
			items[i] = min + rand() % (max - min + 1);
		}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			items[i] = i + 1;
		}
		break;
	case 3:
		for (int i = 0; i < count; i++) {
			items[i] = count - i;
		}
		break;
	case 4:
		for (int i = 0, j = count / 2; i < count; i++) {
			if (i < j) {
				items[i] = i;
			}
			if (i >= j) {
				items[i] = count - i;
			}
		}
		break;
	}
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	start = clock();
	///////////////////////////////////////////////////////////////
	int n;
	qsort(items, count, sizeof(int), comp);
	for (n = 0; n < count; n++)
		printf("%d ", items[n]);
	///////////////////////////////////////////////////////////////
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "[" << i + 1 << "]" << ": [" << items[i] << "]\t";
		if (i % 5 == 4) {
			cout << endl;
		}
	}
	cout << endl;
	end = clock();
	cout << "Программа закончила сортировку по методу Шелла за "
		<< (end - start) /*/ CLK_TCK*/ << " секунд." << endl;
	free(items);
}
int comp(const void* i, const void* j) {
	return *(int*)i - *(int*)j;
}