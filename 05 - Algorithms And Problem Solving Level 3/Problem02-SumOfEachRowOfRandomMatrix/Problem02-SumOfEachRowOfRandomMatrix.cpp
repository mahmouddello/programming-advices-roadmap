#include <iostream>
#include <iomanip>
#include "D:/MyCPP_Libs/headers/random_utils.h"

using namespace std;

// Problem: Write a C++ code that fills a 3x3 (2D) matrix with random numbers. Then print the sum of each row

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = random_utils::randomNumberInRange(1, 100);
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

void SumOfEachRow2DArray(int array[3][3], short rows, short columns)
{
	int sum;
	for (short i = 0; i < rows; i++) {
		sum = 0;
		for (short j = 0; j < columns; j++) {
			sum += array[i][j];
		}
		cout << "Row " << i + 1 << " Sum: " << sum << endl;
	}
}

int main() {

	srand((unsigned)time(NULL)); // random seed, called only once in main

	int array[3][3];
	Fill2DArrayWithRandomNumbers(array, 3, 3);

	cout << "The following is 3x3 random matrix:" << endl;
	Print2DArray(array, 3, 3);

	cout << "\nThe following is the sum of each row in the matrix: " << endl;
	SumOfEachRow2DArray(array, 3, 3);

	return 0;
}
