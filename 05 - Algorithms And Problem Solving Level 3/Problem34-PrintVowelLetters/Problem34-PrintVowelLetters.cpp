#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string ReadString()
{
	string sentence;
	cout << "Please enter your string?" << endl;
	getline(cin, sentence);

	return sentence;
}

bool IsVowel(char c)
{
	c = tolower(c);

	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

void PrintVowelLetters(const string& sentence)
{
	short count = 0;

	for (short i = 0; i < sentence.length(); i++)
		if (IsVowel(sentence[i]))
			cout << setw(3) << sentence[i];
}

int main()
{
	string s1 = ReadString();

	cout << "\nVowel Letters: ";
	PrintVowelLetters(s1);

	return 0;
}