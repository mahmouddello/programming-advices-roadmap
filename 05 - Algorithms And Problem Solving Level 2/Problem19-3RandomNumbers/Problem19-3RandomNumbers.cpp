#include <iostream>

using namespace std;

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

int main()
{
	// seeds the random number generator in c++, called only once.
	srand((unsigned)time(NULL));

	cout << RandomNumber(3, 7) << endl;
	cout << RandomNumber(3, 7) << endl;
	cout << RandomNumber(3, 7) << endl;
	
}