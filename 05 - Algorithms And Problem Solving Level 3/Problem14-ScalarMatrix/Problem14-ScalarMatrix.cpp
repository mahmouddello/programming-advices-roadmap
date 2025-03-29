#include <iostream>
#include <iomanip>
#include "D:\MyCPP_Libs\RandomLib.h";

using namespace std;

bool IsTrueScalarMatrix(int array[3][3], short rows, short columns) 
{
	short matrixDiagonalElement = array[0][0];

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (i == j && array[i][j] != matrixDiagonalElement)
				return false;
			else if (i != j && array[i][j] != 0)
				return false;
		}
	}

	return true;
}

int main() {

	int scalarMatrix[3][3] =
	{
		{9, 0, 0},
		{0, 9, 0},
		{0, 0, 9}
	};

	int notScalarMatrix[3][3] =
	{
		{1, 2, 3},
		{4, 1, 6},
		{7, 8, 1}
	};

	if (IsTrueScalarMatrix(scalarMatrix, 3, 3))
		cout << "Yes, it's an scalar matrix." << endl;
	else
		cout << "No, it's not an scalar matrix." << endl;

	if (IsTrueScalarMatrix(notScalarMatrix, 3, 3))
		cout << "\nYes, it's an scalar matrix." << endl;
	else
		cout << "\nNo, it's not an scalar matrix." << endl;

	return 0;
}