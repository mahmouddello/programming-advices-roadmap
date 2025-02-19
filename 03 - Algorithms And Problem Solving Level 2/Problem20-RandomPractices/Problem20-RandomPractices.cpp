#include <iostream>

using namespace std;

// Programming Advices Solution is in Notion!

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

enum enCharType {
	smallLetter = 1,
	capitalLetter = 2,
	sepcialChar = 3,
	digit = 4
};

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

int main()
{
	// seeds the random number generator in c++, called only once.
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enCharType::smallLetter) << endl;
	cout << GetRandomCharacter(enCharType::capitalLetter) << endl;
	cout << GetRandomCharacter(enCharType::sepcialChar) << endl;
	cout << GetRandomCharacter(enCharType::digit) << endl;

}