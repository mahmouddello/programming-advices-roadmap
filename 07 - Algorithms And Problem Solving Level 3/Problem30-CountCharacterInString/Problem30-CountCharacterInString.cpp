#include <iostream>
#include <string>

using namespace std;

string ReadString();
char ReadChar();
int CountCharacter(string, char);

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

char ReadChar()
{
	char c;
	cout << "Please enter a character? " << endl;
	cin >> c;

	return c;
}

int CountCharacter(string s1, char c)
{
	int count = 0;

	for (short i = 0; i < s1.length(); i++)
		if (s1[i] == c)
			count++;

	return count;
}

int main()
{
	string s1 = ReadString();
	cout << endl;
	
	char c = ReadChar();

	cout << "Letter '" << c << "' count = " << CountCharacter(s1, c) << endl;

	return 0;
}