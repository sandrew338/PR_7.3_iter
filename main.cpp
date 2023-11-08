// Lab_7_3.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.3)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 17
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void SearchMax(int** a, const int n, int level, int &x, int &y, int &value);
void Create(int** a, const int n, const int Low, const int High);
void SortDiagonal(int**& a, const int n);
void Print(int** a, const int n);
void SwapElements(int** &a, const int n, int x, int y, int i);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	cout << "After modification: " << endl;
	//
	SortDiagonal(a, n);
	Print(a, n);
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void SortDiagonal(int** &a, const int n)
{
	int x, y, value;
	for (int i = 0; i < n; i++)
	{

		SearchMax(a, n, i, x, y, value);
		SwapElements(a, n, x, y, i);
		/*cout << i << ". value = " << value << endl << "x = " << x << endl << "y = " << y << endl << "===============" << endl;
		Print(a, n);*/
		
	}
	cout << endl;
}
void SearchMax(int** a, const int n, int level, int &x, int &y, int &value) 
{
	int max = a[level][0];
	value = max;
	x = level;
	y = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//i can't be equal j till row ~ !(i != j && i < level)
			if (a[i][j] > max && !(i == j && i < level))
			{
				max = a[i][j];
				value = max;
				x = i;
				y = j;
			}
		}
	}

}
void SwapElements(int** &a, const int n, int x, int y, int i)
{
	int temp = a[i][i];
	a[i][i] = a[x][y];
	a[x][y] = temp;
}