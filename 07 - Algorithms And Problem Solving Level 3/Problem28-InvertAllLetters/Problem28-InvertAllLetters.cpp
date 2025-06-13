#include <iostream>
#include <string>

using namespace std;

string ReadString();
string InvertAllLettersCase(string);
char InvertCharacter(char);

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

string InvertAllLettersCase(string s1)
{
	for (short i = 0; i < s1.length(); i++)
	{
		s1[i] = InvertCharacter(s1[i]);
	}

	return s1;
}

char InvertCharacter(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

int main()
{
	string s1 = ReadString();

	s1 = InvertAllLettersCase(s1);

	cout << "\nString after inverting all letters case:\n" << s1 << endl;

	return 0;
}