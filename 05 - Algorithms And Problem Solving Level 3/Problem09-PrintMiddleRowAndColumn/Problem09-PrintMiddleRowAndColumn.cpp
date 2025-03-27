#include <iostream>
#include <iomanip>
#include "D:\MyCPP_Libs\RandomLib.h";

using namespace std;

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = RandomLib::RandomNumberInRange(1, 10);
		}
	}
}

void Print2DArray(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}

void PrintMiddleRowInMatrix(int array[3][3], short rows, short columns)
{
	short middleRow = rows / 2;

	for (short i = 0; i < columns; i++)
		cout << setw(3) << array[middleRow][i] << " ";
}

void PrintMiddleColumnInMatrix(int array[3][3], short rows, short columns)
{
	short middleCol = columns / 2;

	for (short i = 0; i < rows; i++)
		cout << setw(3) << array[i][middleCol] << " ";
}

int main()
{
	srand((unsigned)time(NULL));

	int array[3][3];

	Fill2DArrayWithRandomNumbers(array, 3, 3);
	Print2DArray(array, 3, 3);


	cout << "\nThe following is the middle row in the matrix:" << endl;
	PrintMiddleRowInMatrix(array, 3, 3);
	
	cout << "\nThe following is the middle column in the matrix:" << endl;
	PrintMiddleColumnInMatrix(array, 3, 3);

	return 0;
}