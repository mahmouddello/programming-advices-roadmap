#include <iostream>

using namespace std;

int FindNumberIndex(int array[100], const int& length, int& numberToSearch)
{
	for (int i = 0; i < length; i++)
		if (numberToSearch == array[i])
			return i; // return index i if found

	return -1; // return -1 if not found
}

bool IsNumberInArray(int array[100], const int& length, int& numberToSearch)
{
	return FindNumberIndex(array, length, numberToSearch) != -1;
}

void AddArrayElement(int number, int arrDest[100], int& arrDestLen)
{
	arrDestLen++;
	arrDest[arrDestLen - 1] = number;
}

void CopyDistinctNumbers(int arraySrc[10], int arrayDest[10], const int& arrSrcLen, int& arrDestLen)
{
	for (int i = 0; i < arrSrcLen; i++)
	{
		if (!IsNumberInArray(arrayDest, arrDestLen, arraySrc[i]))
		{
			AddArrayElement(arraySrc[i], arrayDest, arrDestLen);
		}
	}
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int main()
{
	int array1[] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
	short array1Length = sizeof(array1) / sizeof(int);

	int array2[10], array2Length = 0;

	cout << "Array 1 Elements:\n";
	PrintArray(array1, array1Length);

	CopyDistinctNumbers(array1, array2, array1Length, array2Length);

	cout << "\nArray 2 Distinct Elements:\n";
	PrintArray(array2, array2Length);

	return 0;
}