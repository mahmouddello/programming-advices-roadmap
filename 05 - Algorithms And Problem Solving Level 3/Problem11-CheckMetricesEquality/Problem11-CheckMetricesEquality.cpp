#include <iostream>
#include <iomanip>
#include "../mylibs/headers/random_utils.h"

using namespace std;

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = random_utils::randomNumberInRange(1, 100);
		}
	}
}

int Sum2DMatrix(int array[3][3], short rows, short columns) {
	int sum = 0;

	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			sum += array[i][j];
		}
	}

	return sum;
}

bool isMetricesEqual(int arr1[3][3], int arr2[3][3], short rows, short columns) {
	return Sum2DMatrix(arr1, rows, columns) == Sum2DMatrix(arr2, rows, columns);
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

	if (!isMetricesEqual(array1, array2, 3, 3))
		cout << "\nNO, metrices sum is NOT equal." << endl;

	else
		cout << "\nYES, metrices sum is equal." << endl;

	return 0;
}