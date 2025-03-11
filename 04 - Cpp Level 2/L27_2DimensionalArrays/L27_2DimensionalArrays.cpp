#include <iostream>

using namespace std;

void Fill2DimensionalArr(int array[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = (i + 1) * (j + 1);
		}
	}
}

void Print2DimensionalArray(int array[10][10]) 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%0*d ", 2, array[i][j]);
		}

		cout << endl;
	}
}

int main() {

	//// 3 rows, and 4 columns, array[rows][columns]
	//int array[3][4] = {
	//	{1, 2, 3, 4},
	//	{5, 6, 7, 8},
	//	{9, 10, 11, 12}
	//};

	//// index access starts from 0
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		cout << array[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	int multiplicationTableArr[10][10];
	Fill2DimensionalArr(multiplicationTableArr);
	Print2DimensionalArray(multiplicationTableArr);

	return 0;
}