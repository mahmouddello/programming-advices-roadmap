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

void FindIntersectedNumbers(int arr1[3][3], int arr2[3][3], int arrIntersect[10], short &length, short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			if (isNumberExistsInMatrix(arr2, arr1[i][j], rows, columns))
			{
				arrIntersect[length] = arr1[i][j];
				length++;
			}
		}
	}
}

void Print1DArray(int array[10], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << setw(4) << array[i];
	}

	cout << endl;
}

int main() {

	int matrix1[3][3] = { {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };
	int matrix2[3][3] = { {5, 8, 90}, {22, 77, 1}, {10, 8, 3} };

	cout << "Matrix1:" << endl;
	Print2DArray(matrix1, 3, 3);
	
	cout << "\nMatrix2:" << endl;
	Print2DArray(matrix2, 3, 3);

	int intersectedNumbersMatrix[10];
	short length = 0;

	FindIntersectedNumbers(matrix1, matrix2, intersectedNumbersMatrix, length, 3, 3);

	if (length > 0)
	{
		cout << "\nIntersected Numbers are: ";
		Print1DArray(intersectedNumbersMatrix, length);
	}
	else
		cout << "\nThere are no intersected elements between two metricies" << endl;

	return 0;
}