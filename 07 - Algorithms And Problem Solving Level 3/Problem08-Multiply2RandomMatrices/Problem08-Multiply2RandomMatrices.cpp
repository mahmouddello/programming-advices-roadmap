#include <iostream>
#include <iomanip>
#include "../mylibs/headers/random_utils.h"

using namespace std;

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = random_utils::randomNumberInRange(1, 100);
		}
	}
}

void MultiplyTwo2DMatrices(int arr1[3][3], int arr2[3][3], int arrMul[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++)
		{
			arrMul[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

void Print2DArray(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			printf("%0*d ", 2, array[i][j]);
		}
		cout << endl;
	}
}

int main() {

	srand((unsigned)time(NULL)); // seeds the random in C++

	int array1[3][3], array2[3][3];

	cout << "First Random 3x3 Matrix:" << endl;
	Fill2DArrayWithRandomNumbers(array1, 3, 3);
	Print2DArray(array1, 3, 3);

	cout << "\nSecond Random 3x3 Matrix:" << endl;
	Fill2DArrayWithRandomNumbers(array2, 3, 3);
	Print2DArray(array2, 3, 3);

	int arrayMultiply[3][3];
	MultiplyTwo2DMatrices(array1, array2, arrayMultiply, 3, 3);

	cout << "\nMatrices multiplication result:" << endl;
	Print2DArray(arrayMultiply, 3, 3);

	return 0;
}