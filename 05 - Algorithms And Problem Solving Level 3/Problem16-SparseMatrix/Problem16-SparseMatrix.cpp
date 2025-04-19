#include <iostream>
#include <iomanip>
#include "D:/MyCPP_Libs/headers/input_utils.h"

using namespace std;

int CountNumberIn2DMatrix(int array[3][3], short rows, short columns, short numberToCount)
{
	int count = 0;

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (array[i][j] == numberToCount)
				count++;
		}
	}

	return count;
}

bool isSparseMatrix(int array[3][3], short rows, short columns) 
{
	short matrixSize = rows * columns;
	short zerosCount = CountNumberIn2DMatrix(array, rows, columns, 0);

	return zerosCount > (matrixSize / 2);

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

void PrintSparseMatrixResult(int array[3][3], short rows, short columns)
{
	if (isSparseMatrix(array, rows, columns))
		cout << "\nYES, It's a sparse matrix." << endl;
	else
		cout << "\nNO, It's not a sparse matrix." << endl;
}

int main() {

	int matrix1[3][3] = {
		{10, 0, 12},
		{20, 15, 1},
		{0, 0, 9}
	};
	
	int matrix2[3][3] = {
		{0, 0, 12},
		{0, 0, 1},
		{0, 0, 9}
	};

	cout << "Matrix 1:" << endl;
	Print2DArray(matrix1, 3, 3);
	PrintSparseMatrixResult(matrix1, 3, 3);

	cout << "\n------------------\n" << endl;

	cout << "Matrix 2:" << endl;
	Print2DArray(matrix2, 3, 3);
	PrintSparseMatrixResult(matrix2, 3, 3);

	return 0;
}