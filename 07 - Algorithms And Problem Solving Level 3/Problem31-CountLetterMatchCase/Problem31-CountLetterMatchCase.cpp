#include <iostream>
#include <string>

using namespace std;

string ReadString();
char ReadChar();
char InvertCharacterCase(char);
int CountCharacter(string, char, bool);

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

char InvertCharacterCase(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

char ReadChar()
{
	char c;
	cout << "Please enter a character? " << endl;
	cin >> c;

	return c;
}

int CountCharacter(string s1, char c, bool matchCase = true)
{
	int count = 0;

	for (short i = 0; i < s1.length(); i++)
	{
		if (matchCase)
		{
			if (s1[i] == c)
				count++;
		}
		else
		{
			if (tolower(s1[i]) == tolower(c))
				count++;
		}
	}

	return count;
}

int main()
{
	string s1 = ReadString();
	cout << endl;

	char c = ReadChar();

	cout << "Letter '" << c << "' count = " << CountCharacter(s1, c) << endl;
	cout << "Letter '" << c << "' or '" << InvertCharacterCase(c);
	cout << "' count = " << CountCharacter(s1, c, false) << endl;

	return 0;
}