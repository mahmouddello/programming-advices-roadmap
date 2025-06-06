#include <iostream>
#include <iomanip>
#include "../mylibs/headers/input_utils.h"

using namespace std;

void Print2DArray(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}

bool isNumberExistsInMatrix(int array[3][3], int number, short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (array[i][j] == number)
				return true;
		}
	}

	return false;
}

int main() {

	int matrix[3][3] = { {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };
	
	cout << "Matrix:" << endl;
	Print2DArray(matrix, 3, 3);

	short number = input_utils::readNumber("Please enter the number to look for in the matrix? ");

	if (isNumberExistsInMatrix(matrix, number, 3, 3))
		cout << "\nYes, it is there." << endl;
	else
		cout << "\nNo, it's not there." << endl;

	return 0;
}