#include <iostream>
#include <iomanip>
#include "D:/MyCPP_Libs/headers/random_utils.h"

using namespace std;

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = random_utils::randomNumberInRange(1, 100);
		}
	}
}

bool isMetricesTypical(int arr1[3][3], int arr2[3][3], short rows, short columns) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < rows; j++) {
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	return true;
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

	srand((unsigned)time(NULL));

	int array1[3][3], array2[3][3];

	Fill2DArrayWithRandomNumbers(array1, 3, 3);
	Fill2DArrayWithRandomNumbers(array2, 3, 3);

	cout << "Matrix 1:" << endl;
	Print2DArray(array1, 3, 3);

	cout << "\nMatrix 2:" << endl;
	Print2DArray(array2, 3, 3);

	if (!isMetricesTypical(array1, array2, 3, 3))
		cout << "\nNO, metrices are NOT typical." << endl;

	else
		cout << "\nYES, metrices are typical." << endl;

	return 0;
}