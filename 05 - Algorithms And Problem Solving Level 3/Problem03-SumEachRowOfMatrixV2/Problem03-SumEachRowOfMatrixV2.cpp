#include <iostream>
#include <iomanip>
#include "D:/MyCPP_Libs/RandomLib.h";

/*
	Problem 03: Write a C++ code to create a random 3x3 (2D) array, print it
	,and then get the sum of each row and store it in 1D array then print 
	each row sum result on the screen.
*/

using namespace std;

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = RandomLib::RandomNumberInRange(1, 100);
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

int RowSum(int array[3][3], short rowNumber, short cols)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += array[rowNumber][i];

	return sum;
}

void SaveSumOfRowsIn1DArray(int originalArray[3][3], int array1D[3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
		array1D[i] = RowSum(originalArray, i, cols);
}

void PrintRowSum(int array1D[3], int length)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Row " << i + 1 << " Sum: " << array1D[i] << endl;
	}
}

int main() 
{

	int array2D[3][3];
	int array1D[3];

	Fill2DArrayWithRandomNumbers(array2D, 3, 3);
	Print2DArray(array2D, 3, 3);

	cout << "\nHere is each row sum: " << endl;
	SaveSumOfRowsIn1DArray(array2D, array1D, 3, 3);
	PrintRowSum(array1D, 3);

	return 0;
}