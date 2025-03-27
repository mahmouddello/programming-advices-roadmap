#include <iostream>
#include <iomanip>

#include "D:/MyCPP_Libs/RandomLib.h";

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

int ColumnSum(int array[3][3], short rows, short columnNumber)
{
	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		sum += array[i][columnNumber];
	}

	return sum;
}

void PrintColumnSum(int array[3][3], short rows, short columns)
{
	for (int i = 0; i < columns; i++)
	{
		cout << "Column " << i + 1 << " Sum: " << ColumnSum(array, rows, i) << endl;
	}
}

int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	
	Fill2DArrayWithRandomNumbers(arr, 3, 3);
	Print2DArray(arr, 3, 3);

	cout << "\nHere is sum of each columns in the matrix:\n";
	PrintColumnSum(arr, 3, 3);

	return 0;
}