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

bool isPalindromeMatrix(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns / 2; j++)
		{
			if (array[i][j] != array[i][columns - j - 1])
				return false;
		}
	}
	return true;
}

int main()
{
	int matrix1[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7} };
	int matrix2[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 8} };

	cout << "Matrix1:" << endl;
	Print2DArray(matrix1, 3, 3);

	if (isPalindromeMatrix(matrix1, 3, 3))
		cout << "\nYes, it's palindrome matrix." << endl;
	else
		cout << "\nNo, it's not a palindrome matrix." << endl;

	cout << "\nMatrix2:" << endl;
	Print2DArray(matrix2, 3, 3);

	if (isPalindromeMatrix(matrix2, 3, 3))
		cout << "\nYes, it's palindrome matrix." << endl;
	else
		cout << "\nNo, it's not a palindrome matrix." << endl;

	return 0;
}