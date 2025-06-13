#include <iostream>
#include <iomanip>
#include "../mylibs/headers/input_utils.h"

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

void Print2DArray(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int matrix[3][3] = {
		{9, 1, 12},
		{0, 9, 1},
		{0, 9, 9}
	};

	Print2DArray(matrix, 3, 3);

	int number = input_utils::readNumber("\nEnter the number to count in matrix? ");
	int numberFrequeny = CountNumberIn2DMatrix(matrix, 3, 3, number);

	if (numberFrequeny > 0)
		cout << "\nNumber " << number << " count in matrix: " << numberFrequeny << endl;
	else
		cout << "\nThe matrix doesn't include the number: " << number << endl;

	return 0;
}