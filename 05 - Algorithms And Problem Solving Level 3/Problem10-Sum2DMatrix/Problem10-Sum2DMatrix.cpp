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

int Sum2DMatrix(int array[3][3], short rows, short columns)
{
	int sum = 0;
	
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			sum += array[i][j];
		}
	}

	return sum;
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

	int array[3][3];
	Fill2DArrayWithRandomNumbers(array, 3, 3);

	cout << "Matrix 1:" << endl;
	Print2DArray(array, 3, 3);

	cout << "\nMatrix 1 elements sum: " << Sum2DMatrix(array, 3, 3) << endl;

	return 0;
}