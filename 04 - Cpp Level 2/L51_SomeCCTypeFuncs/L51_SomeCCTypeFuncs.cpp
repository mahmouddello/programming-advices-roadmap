#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	char x;
	char w;

	x = toupper('a');
	w = tolower('A');

	cout << "converting a to A: " << x << endl;
	cout << "converting A to a: " << w << endl;

	// Digits (A to Z)
	// returns zero if not, and non zero of yes
	cout << "isupper('A') " << isupper('A') << endl;

	// lower case (a to z)
	// returns zero if not, and non zero of yes
	cout << "islower('A') " << islower('A') << endl;

	// Digits (0 to 9)
	// returns zero if not, and non zero of yes
	cout << "isdigit('A') " << isdigit('A') << endl;

	// Digits (A to Z)
	// returns zero if not, and non zero of yes
	cout << "isupper('A') " << isupper('A') << endl;

	// lower case (a to z)
	// returns zero if not, and non zero of yes
	cout << "islower('a') " << islower('a') << endl;

	// Digits (0 to 9)
	// returns zero if not, and non zero of yes
	cout << "isdigit('9') " << isdigit('9') << endl;

	// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	// returns zero if not, and non zero of yes
	cout << "ispunct('!') " << ispunct('!') << endl;

	return 0;
}