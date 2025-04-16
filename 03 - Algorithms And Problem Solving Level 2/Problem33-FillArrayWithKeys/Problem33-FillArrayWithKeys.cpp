#include <iostream>

using namespace std;

enum enCharType {
	smallLetter = 1,
	capitalLetter = 2,
	sepcialChar = 3,
	digit = 4
};

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int from, int to)
{

	/*
		For example, if you want numbers between 3 and 7:

		(7 - 3 + 1) = 5, so rand() % 5 gives numbers from 0 to 4.
		Adding 3 shifts it to 3 to 7.
	*/

	int randomNumber = rand() % (to - from + 1) + from;

	return randomNumber;
}

char GetRandomCharacter(enCharType charType)
{
	switch (charType)
	{
	case enCharType::smallLetter: return char(RandomNumber(97, 122));
	case enCharType::capitalLetter: return char(RandomNumber(65, 90));
	case enCharType::sepcialChar: return char(RandomNumber(33, 47));
	case enCharType::digit: return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enCharType charType, int length)
{
	string word = "";

	for (int i = 1; i <= length; i++)
	{
		word += GetRandomCharacter(charType);
	}

	return word;
}

string GenerateKey(int length)
{
	string key = "";

	for (int i = 0; i < length; i++)
	{
		key += GenerateWord(enCharType::capitalLetter, length);

		if (i < length - 1)
			key += "-";

	}

	return key;

}

void FillArrayWithKeys(string array[100], const int& arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		array[i] = GenerateKey(4);
	}
}

void PrintArray(string array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << "Array [" << i << "]: " << array[i] << "\n";
}

int main()
{
	srand((unsigned)time(NULL)); // random seed, called only once
	
	string arrayOfKeys[100];

	int arrayLength = ReadPositiveNumber("How many keys you want to generate and store? ");

	FillArrayWithKeys(arrayOfKeys, arrayLength);

	cout << "\nArray of keys:\n";
	PrintArray(arrayOfKeys, arrayLength);

	return 0;
}