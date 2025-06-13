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

char InvertCharacterCase(char c)
{
	if (c >= 65 && c <= 90)
		return char(c + 32);

	return char(c - 32);
}

char InvertCharProgrammingAdvices(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

int main()
{
	char c = ReadChar();

	cout << "\nCharacter after inverting case:\n" << InvertCharacterCase(c) << endl;

	cout << "\nInvert Char Programming Advices:\n" << InvertCharProgrammingAdvices(c) << endl;
}
