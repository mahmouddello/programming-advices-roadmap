#include <iostream>
#include <iomanip>

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

int FindMinInMatrix(int array[3][3], short rows, short columns)
{
	int min = array[0][0];
	
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (min > array[i][j])
				min = array[i][j];
		}
	}

	return min;
}

int FindMaxInMatrix(int array[3][3], short rows, short columns)
{
	int max = array[0][0];
	
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (max < array[i][j])
				max = array[i][j];
		}
	}

	return max;
}

int main()
{
	int matrix[3][3] = { {77, 5, 12}, {22, 20, 6}, {14, 3, 9} };

	cout << "Matrix1:" << endl;
	Print2DArray(matrix, 3, 3);

	int min = FindMinInMatrix(matrix, 3, 3);
	int max = FindMaxInMatrix(matrix, 3, 3);

	cout << "\nMinimum number: " << min << endl;
	cout << "\nMaximum number: " << max << endl;

	return 0;
}