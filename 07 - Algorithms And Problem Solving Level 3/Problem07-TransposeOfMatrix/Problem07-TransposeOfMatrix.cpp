#include <iostream>
#include <iomanip>

using namespace std;

void Fill2DMatrixWithOrder(int array[3][3], short rows, short columns)
{
	short start = 1;

	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = start;
			start++;
		}
	}
}

void Transpose2DMatrix(int array[3][3], int arrTranspose[3][3], short rows, short columns)
{
	short temp = 0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			arrTranspose[i][j] = array[j][i];
		}
	}
}

void Print2DMatrix(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int array[3][3], arrayTranspose[3][3];

	Fill2DMatrixWithOrder(array, 3, 3);
	Transpose2DMatrix(array, arrayTranspose, 3, 3);

	cout << "Here is an orderd 3x3 matrix:\n";
	Print2DMatrix(array, 3, 3);

	cout << "\nHere is the transpose of an orderd 3x3 matrix:\n";
	Print2DMatrix(arrayTranspose, 3, 3);

	return 0;
}