#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
	char c;
	cout << "Please enter a character? " << endl;
	cin >> c;

	return c;
}

bool isVowel(const char& c)
{
	const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	const short size = sizeof(vowels) / sizeof(vowels[0]);

	for (short i = 0; i < size; ++i)
		if (tolower(c) == vowels[i])
			return true;

	return false;
}

bool isVowelV2(char& c)
{
	c = tolower(c);

	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

int main()
{
	char c = ReadChar();

	if (isVowel(c))
		cout << "\nYES, it is a vowel letter." << endl;
	else
		cout << "\nNO, it is not a vowel letter." << endl;

	return 0;
}
