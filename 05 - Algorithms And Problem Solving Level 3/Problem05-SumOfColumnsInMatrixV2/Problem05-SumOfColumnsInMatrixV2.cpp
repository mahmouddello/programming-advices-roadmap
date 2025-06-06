#include <iostream>
#include <iomanip>

#include "../mylibs/headers/random_utils.h";

using namespace std;

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

int ColumnSum(int array[3][3], short rows, short columnNumber)
{
	int sum = 0;

	for (short i = 0; i < rows; i++)
	{
		sum += array[i][columnNumber];
	}

	return sum;
}

void InsertColumnSumToArr(int array[3][3], int arrSum[3], short rows, short columns)
{
	for (short i = 0; i < columns; i++)
		arrSum[i] = ColumnSum(array, rows, i);
}

void PrintColumnSum(int array[3][3], int arraySum[3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		cout << "Column " << i + 1 << " Sum: " << arraySum[i] << endl;
	}
}

int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrColSum[3];

	Fill2DArrayWithRandomNumbers(arr, 3, 3);
	Print2DArray(arr, 3, 3);

	InsertColumnSumToArr(arr, arrColSum, 3, 3);
	cout << "\nHere is sum of each columns in the matrix:\n";
	PrintColumnSum(arr, arrColSum, 3, 3);

	return 0;
}