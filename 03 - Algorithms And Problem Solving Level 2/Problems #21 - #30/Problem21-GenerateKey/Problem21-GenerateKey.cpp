#include <iostream>

using namespace std;

/*
	Programming Advices Solution: 


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

//int randomNumber = rand() % (from - to + 1) + from;
//
//return randomNumber;
//}
//
//char GetRandomCharacter(enCharType charType)
//{
//	switch (charType)
//	{
//	case enCharType::smallLetter: return char(RandomNumber(97, 122));
//	case enCharType::capitalLetter: return char(RandomNumber(65, 90));
//	case enCharType::sepcialChar: return char(RandomNumber(33, 47));
//	case enCharType::digit: return char(RandomNumber(48, 57));
//	}
//}
//
//string GenerateWord(enCharType charType, int length)
//{
//	string word = "";
//
//	for (int i = 1; i <= length; i++)
//	{
//		word += GetRandomCharacter(charType);
//	}
//
//	return word;
//}
//
//string GenerateKey(int length)
//{
//	string key = "";
//
//	for (int i = 0; i < length; i++)
//	{
//		key += GenerateWord(enCharType::capitalLetter, length) + "-";
//	}
//
//	return key;
//
//}
//
//void GenerateKeys(int numberOfKeys)
//{
//	for (int i = 1; i <= numberOfKeys; i++)
//	{
//		cout << "Key [" << i << "]: ";
//		cout << GenerateKey(4) << endl;
//	}
//}
//
//int main()
//{
//
//	// seeds the random number generator in c++, called only once.
//	srand((unsigned)time(NULL));
//
//	int numberOfKeys = ReadPositiveNumber("Please enter the number of keys: ");
//
//	GenerateKeys(numberOfKeys);
//
//	return 0;
//
//}

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

char GenerateRandomCharacter()
{
	return char(RandomNumber(65, 90));
}

void GenerateKey(int quantity)
{
	string key = "";

	for (int i = 0; i < quantity; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				key += GenerateRandomCharacter();
			}

			if (j < 3)
				key += "-";
		}

		cout << "Key [" << i << "]: " << key << endl;

		key = "";
	}
}

int main()
{
	int quantity = ReadPositiveNumber("Please enter a positive number (key quantity): ");

	GenerateKey(quantity);

	return 0;
}